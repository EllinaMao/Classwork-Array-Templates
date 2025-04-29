#pragma once


class DrivigCards
{
	int numb_speed_over;
	const double max_speed;

public:
	DrivigCards();
	DrivigCards(int nmb_spd_ov, double mx_spd);

	int GetNumbSpdOver() const;
	double GetMaxSpeed() const;

	void SetNumbSpdOver(int nmb_spd_ov);



};