
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

    void setFire(int x, int y) {
        fire = std::make_pair(x, y);
    }
    std::pair<int, int> getFire() {
        return fire;
    }

    void getDesk(int32_t(*arr)[10]){
    	for(int i = 0; i < 10; i++){
    		for(int j = 0; j < 10; j++){
    			arr[i][j] = this->desk[i][j];
    		}
    	}
    }
    void setDesk(int32_t i, int32_t j, int32_t status)
    {
       	desk[i][j] = status;
    }

protected:
    ModelListener* modelListener;
    std::pair<int, int> fire;
    int32_t desk[10][10];
};

#endif // MODEL_HPP
