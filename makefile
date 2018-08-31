all: RobotGame


RobotGame: Base.cpp fighters.cpp Robot.cpp main.cpp
	g++ -o RG Base.cpp fighters.cpp Robot.cpp main.cpp

clean:
	rm -f RG
