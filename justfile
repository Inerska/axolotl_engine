cmake:
    xmake project -k cmake

run: build
    xmake run game_engine_exe

build:
    xmake

test: build
    xmake run tests
 
install: build
    xmake install
