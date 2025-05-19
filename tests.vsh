# VIM: let b:vsh_lvl=2

export MAKE="make -Rrd --warn-undefined-variables"
export MAKE="make -Rrk --warn-undefined-variables"

:lcd tests

#> Compile & Run
${MAKE:-make}
diff <(
	echo "./std-tester"
	./std-tester
) <(
	echo "./ft-tester"
	./ft-tester | sed "s/ft::/std::/g"
)
#<

${MAKE:-make} fclean
${MAKE:-make} re

ls -lh $(which c++)

c++ --version

./tester 1
