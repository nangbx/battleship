#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>


Model::Model() : modelListener(0), fire(std::make_pair(-1, -1))
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			player1Desk[i][j] = 0;
			player2Desk[i][j] = 0;
		}
	}
}

void Model::tick()
{

}
