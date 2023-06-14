#ifndef HIGHSCORES_H_
#define HIGHSCORES_H_

class HighScores {
public:
	HighScores();
	virtual ~HighScores();

	int getNumScores();
	int getScore(int i);

	void addScore(int aScore);
	void printScores();

private:
	int myNumScores;
	int myScores[10];

	int findLocationToInsert(int newScore);
	void shiftUp(int fromIndex);
};

#endif /* HIGHSCORES_H_ */
