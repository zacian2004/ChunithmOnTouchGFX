#ifndef MODEL_HPP
#define MODEL_HPP

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

    void setFinalScore(int score);
    int getFinalScore() const;

    void setStats(int perfect, int good, int miss);
	int getPerfectCount() const;
	int getGoodCount() const;
	int getMissCount() const;

	void setSelectedSong(int index) { selectedSongIndex = index; }
	int getSelectedSong() const { return selectedSongIndex; }

protected:
    ModelListener* modelListener;

private:
    int finalScore = 0;
    int perfectCount = 0;
    int goodCount = 0;
    int missCount = 0;
    int selectedSongIndex;
};

#endif // MODEL_HPP
