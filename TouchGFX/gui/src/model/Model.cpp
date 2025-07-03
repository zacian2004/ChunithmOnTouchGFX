#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() :
	modelListener(0),
	finalScore(0),
	perfectCount(0),
	goodCount(0),
	missCount(0)
{

}

void Model::tick()
{

}

void Model::setFinalScore(int score)
{
    finalScore = score;
}

int Model::getFinalScore() const
{
    return finalScore;
}

void Model::setStats(int perfect, int good, int miss)
{
    perfectCount = perfect;
    goodCount = good;
    missCount = miss;
}

int Model::getPerfectCount() const
{
    return perfectCount;
}

int Model::getGoodCount() const
{
    return goodCount;
}

int Model::getMissCount() const
{
    return missCount;
}
