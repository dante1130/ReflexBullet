#ifndef LEADERBOARDS_H
#define LEADERBOARDS_H

#include <vector>
#include <string>
#include <iostream>

struct Record
{
	std::string name;
	float time;
	float accuracy;
};


class Leaderboard
{
	public:
		Leaderboard();

		void SetRecord(Record &r);

		int GetTopRecordTimes(int i);

		int GetTopRecordAccuracy(int i);

		const Record& GetRecord(int i);

		int GetTotalNumberOfRecords();

	private:
		std::vector<Record> records;
		int topTimes[6];
		int topAccuracy[6];

		void IdentifyTopTime(Record &r);

		void IdentifyTopAccuracy(Record& r);



};


#endif