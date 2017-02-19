#
# Group #10
#   Sam Chew - 933191613
#   Riley Harrison
#   Patrick Huarng
#   Susan Onesky
#   Armand Parajon
#   Peter Yetti
#   Nathan Zimmerman
#
# CS162_400_2017Winter
# GroupProj: Paper,Rock,Scissors
# Authored & Submitted by 933191613


CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -03
LDFLAGS = -lboost_date_time

TOPPRG = playgame
ZIPID = GroupProj_Team10.zip

MENU_OBJS       = chewsValidation_v5.o play_game.o Menu.o
OBJS            = Tool.o Rock.o Paper.o Scissors.o RPSGame.o

MENU_SRCS       = chewsValidation_v5.cpp play_game.cpp Menu.cpp
SRCS            = Tool.cpp Rock.cpp Paper.cpp Scissors.cpp RPSGame.cpp

MENU_HEADERS    = chewsValidation_v5.hpp Menu.hpp
HEADERS         = Tool.hpp Rock.hpp Paper.hpp Scissors.hpp RPSGame.hpp

UTILTXT         = Menu_StartOpts.txt Menu_PlayOpts.txt

#General Syntax
#target: dependencies
#	rule to build  (must be TAB line item after target line)

${TOPPRG}: ${OBJS} ${MENU_OBJS} ${HEADERS} ${MENU_HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${MENU_OBJS} -o ${TOPPRG}
	@for i in . . . . . . .; do \
		echo $i; \
	done

${MENU_OBJS}: ${MENU_SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY : clean
clean :
	rm ${TOPPRG} $(MENU_OBJS) ${OBJS} ${UTILTXT}

.PHONY : zip
zip :
	zip -D ${ZIPID} ${HEADERS} ${SRCS} ${UTILTXT} makefile


##### UNIT AND INTEGRATION TESTING #####

UNIT_TESTS_EXE = unitTest
UNIT_TEST_OBJS = UnitTests.o
UNIT_TEST_SRCS = UnitTests.cpp

${UNIT_TESTS_EXE}: ${OBJS} ${UNIT_TEST_OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${UNIT_TEST_OBJS} -o ${UNIT_TESTS_EXE}

${UNIT_TEST_OBJS}: ${UNIT_TEST_SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


IT_TESTS_EXE = integrationTest
IT_TEST_OBJS = IntegrationTest.o
IT_TEST_SRCS = IntegrationTest.cpp

${IT_TESTS_EXE}: ${OBJS} ${IT_TEST_OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${IT_TEST_OBJS} -o ${IT_TESTS_EXE}

${IT_TEST_OBJS}: ${IT_TEST_SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY : testsClean
testsClean :
	rm ${UNIT_TESTS_EXE} ${IT_TESTS_EXE} ${TEST_OBJS}

##### END TESTING #####