#!/usr/bin/env bash
# Test filler vm with given player.
#
# @date     10/10/2018
# @author   Mykola Odnosumov

if [ -z $1 ] || [ -z $2 ] || [ -z $3 ] || [ -z $4 ]; then
	printf "Usage: %s filler_vm maps_dir players_dir your_exe [ repeats ] [ timeout ]\n" $0;
	exit 1;
fi

filler_vm=$1
maps_dir=$2
players_dir=$3
me=$4
repeats=$5
timeout=$6

if ! command -v grealpath &> /dev/null; then
	printf "grealpath utility not found. Try running\nbrew install coreutils\n";
	exit 2;
fi

filler_vm=$(grealpath ${filler_vm})
filler_dir=$(grealpath .)
maps_dir=$(grealpath ${maps_dir})
players_dir=$(grealpath ${players_dir})
me=$(grealpath ${me})

if [ -z ${repeats} ]; then
	repeats=1;
fi
repeats_arr=$(seq 1 1 ${repeats})

if [ -z ${timeout} ]; then
	timeout=1;
fi

won_as_p1=0;
won_as_p2=0;

result_dir=test_results;

function run_test {
	stats_file_p1=${filler_dir}/${result_dir}/$(basename ${1})/$(basename ${2}).stats.p1
	stats_file_p2=${filler_dir}/${result_dir}/$(basename ${1})/$(basename ${2}).stats.p2
	mkdir -p $(dirname ${stats_file_p1});

	if ! [ -f ${stats_file_p1} ] || ! [ -f ${stats_file_p2} ]; then
		echo "${won_as_p1}/${repeats}" > ${stats_file_p1};
		echo "${won_as_p2}/${repeats}" > ${stats_file_p2};
	fi

	${filler_vm} -t ${timeout} -f ${1} -p1 ${2} -p2 ${me} &> /dev/null;
	if cat ${filler_dir}/filler.trace | grep "${me}" | grep won &> /dev/null; then
		won_as_p1=$((won_as_p1 + 1));
		echo "${won_as_p1}/${repeats}" > ${stats_file_p1};
	fi

	${filler_vm} -t ${timeout} -f ${1} -p2 ${2} -p1 ${me} &> /dev/null;
	if cat ${filler_dir}/filler.trace | grep "${me}" | grep won &> /dev/null; then
		won_as_p2=$((won_as_p2 + 1));
		echo "${won_as_p2}/${repeats}" > ${stats_file_p2};
	fi
}

for map in ${maps_dir}/*; do
	printf "Doing map %s\n" $(basename ${map});
	for player in ${players_dir}/*; do
		won_as_p1=0;
		won_as_p2=0;
		for i in ${repeats_arr}; do
			run_test ${map} ${player};
		done
		printf "Finished player %s\n" $(basename ${player});
	done
	printf "Finished map %s\n" $(basename ${map});
done
