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

OBJS = chewsValidation_v5.o play_game.o Menu.o
# Tool.o Rock.o Paper.o Scissors.o RPSGame.o

SRCS = chewsValidation_v5.cpp play_game.cpp Menu.cpp
# Tool.cpp Rock.cpp Paper.cpp Scissors.cpp RPSGame.cpp

HEADERS = chewsValidation_v5.hpp Menu.hpp
# Tool.hpp Rock.hpp Paper.hpp Scissors.hpp RPSGame.hpp

UTILTXT = Menu_StartOpts.txt Menu_PlayOpts.txt
# 

#General Syntax
#target: dependencies
#	rule to build  (must be TAB line item after target line)

${TOPPRG}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${TOPPRG}
	@for i in . . . . . . .; do \
		echo $i; \
	done

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY : clean
clean :
	rm ${TOPPRG} $(OBJS) ${UTILTXT}

.PHONY : zip
zip :
	zip -D ${ZIPID} ${HEADERS} ${SRCS} ${UTILTXT} makefile

