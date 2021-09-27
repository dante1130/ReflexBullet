#include "Leaderboards.h"

Leaderboard::Leaderboard()
{
	topAccuracy[0] = 0;
	topTimes[0] = 0;
}

void Leaderboard::SetRecord(Record &r)
{
	records.push_back(r);
	
	IdentifyTopTime(r);

	IdentifyTopAccuracy(r);
	
}


int Leaderboard::GetTopRecordTimes(int i)
{
	return topTimes[i];
}

int Leaderboard::GetTopRecordAccuracy(int i)
{
	return topAccuracy[i];
}


const Record& Leaderboard::GetRecord(int i)
{
	return records[i];
}

int Leaderboard::GetTotalNumberOfRecords()
{
	return records.size();
}

void Leaderboard::IdentifyTopTime(Record& r)
{
	int topIndex;
	int max = topTimes[0];

	if (max == 0)
	{
		topTimes[0] = 1;
		topTimes[1] = records.size() - 1;
	}
	else
	{
		for (int count = 1; count <= max; count++)
		{
			topIndex = topTimes[count];

			if (records[topIndex].time > r.time || (records[topIndex].time == r.time && records[topIndex].accuracy < r.accuracy))
			{
				for (int i = 5; i > count; i--)
				{
					topTimes[i] = topTimes[i - 1];
				}
				topTimes[count] = records.size() - 1;
				topTimes[0] = topTimes[0] + 1;
				count = 10;
			}
			else
			{
				if (max < 5 && count == max)
				{
					topTimes[count + 1] = records.size() - 1;
					topTimes[0] = topTimes[0] + 1;
					count = 10;
				}
			}

		}
	}
	if (topTimes[0] > 5) { topTimes[0] = 5; }

	return;
}

void Leaderboard::IdentifyTopAccuracy(Record& r)
{
	int topIndex;
	int max = topAccuracy[0];

	if (max == 0)
	{
		topAccuracy[0] = 1;
		topAccuracy[1] = records.size() - 1;
	}
	else
	{
		for (int count = 1; count <= max; count++)
		{
			topIndex = topAccuracy[count];

			if (records[topIndex].accuracy < r.accuracy || (records[topIndex].accuracy == r.accuracy && records[topIndex].time > r.time))
			{
				for (int i = 5; i > count; i--)
				{
					topAccuracy[i] = topAccuracy[i - 1];
				}
				topAccuracy[count] = records.size() - 1;
				topAccuracy[0] = topAccuracy[0] + 1;
				count = 10;
			}
			else
			{
				if (max < 5 && count == max)
				{
					topAccuracy[count + 1] = records.size() - 1;
					topAccuracy[0] = topAccuracy[0] + 1;
					count = 10;
				}
			}

		}
	}

	if (topAccuracy[0] > 5) { topAccuracy[0] = 5; }

	return;
}