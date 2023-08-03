
#ifndef MODEL_HPP
#define MODEL_HPP
#include <functional>

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
protected:
    ModelListener* modelListener;
    std::pair<int, int> fire;
};

#endif // MODEL_HPP
