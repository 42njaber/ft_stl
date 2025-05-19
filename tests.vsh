# VIM: let b:vsh_lvl=2

export MAKE="make -Rrd --warn-undefined-variables"
export MAKE="make -Rrk --warn-undefined-variables"

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

c++ --version

./tester 1
