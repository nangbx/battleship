
#ifndef MODEL_HPP
#define MODEL_HPP
#include <functional>
#include <touchgfx/hal/types.hpp>
#include <vector>

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
    std::vector<std::vector<int8_t>> getDesk()
    {
    	return this->desk;
    }
    void setDesk(int8_t i, int8_t j, int8_t status)
    {
    	desk[i][j] = status;
    }

protected:
    ModelListener* modelListener;
    std::pair<int, int> fire;
    std::vector<std::vector<int8_t>> desk;
};

#endif // MODEL_HPP
