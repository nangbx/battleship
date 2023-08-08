
#ifndef MODEL_HPP
#define MODEL_HPP
#include <functional>
#include <touchgfx/hal/types.hpp>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }
    void tick();

    void setGameMode(int32_t gameMode) {
        this->gameMode = gameMode;
    }
    int32_t getGameMode() {
        return this->gameMode;
    }

    void setIsMultiPlayer(bool b) {
		this->isMultiPlayer = b;
	}
	bool getIsMultiPlayer() {
		return this->isMultiPlayer;
	}

    void getPlayer1Desk(int32_t(*arr)[10]){
    	for(int i = 0; i < 10; i++){
    		for(int j = 0; j < 10; j++){
    			arr[i][j] = this->player1Desk[i][j];
    		}
    	}
    }
    void setPlayer1Desk(int32_t i, int32_t j, int32_t status)
    {
    	player1Desk[i][j] = status;
    }
	void getPlayer2Desk(int32_t (*arr)[10]) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				arr[i][j] = this->player2Desk[i][j];
			}
		}
	}
	void setPlayer2Desk(int32_t i, int32_t j, int32_t status) {
		player2Desk[i][j] = status;
	}
	void setHits(std::pair<int32_t, int32_t> bot[100]) {
		for (int32_t i = 0; i < 100; i++) {
			this->hits[i] = bot[i];
		}
	}
	void getHits(std::pair<int32_t, int32_t>* bot) {
		for (int32_t i = 0; i < 100; i++) {
			bot[i] = this->hits[i];
		}
	}
	void setIndexHit(int32_t index){
		this->indexHit = index;
	}
	int32_t getIndexHit(){
		return this->indexHit;
	}

	void setWinner(int32_t winner) {
		this->winner = winner;
	}
	int32_t getWinner() {
		return this->winner;
	}
	void Init();
protected:
    ModelListener* modelListener;
    std::pair<int32_t, int32_t> hits[100];
    int32_t indexHit;
    int32_t player1Desk[10][10];
    int32_t player2Desk[10][10];
    int32_t winner;
    int32_t gameMode;
    bool isMultiPlayer;
};

#endif // MODEL_HPP
