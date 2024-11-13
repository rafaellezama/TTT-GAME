ttt: clean
	g++ --std=c++14 board.cpp game_state.cpp main.cpp human_player.cpp console.cpp game.cpp pyromancer.cpp swarm.cpp -o ttt
	./ttt

clean:
	@rm -rf ttt
