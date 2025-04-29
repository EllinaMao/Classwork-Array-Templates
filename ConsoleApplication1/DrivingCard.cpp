#include "DrivingCard.h"

DrivigCards::DrivigCards(): max_speed(50)
{
	numb_speed_over = 0;
}

DrivigCards::DrivigCards(int nmb_spd_ov, double mx_spd) : max_speed(mx_spd)
{
	numb_speed_over = nmb_spd_ov;
	
}

int DrivigCards::GetNumbSpdOver() const
{
	return numb_speed_over;
}

double DrivigCards::GetMaxSpeed() const
{
	return max_speed;
}

void DrivigCards::SetNumbSpdOver(int nmb_spd_ov)
{
	numb_speed_over = nmb_spd_ov;
}
