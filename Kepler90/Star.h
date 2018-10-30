#pragma once
class Star
{
public:
	Star(
		double radius // in Earths
	);

	void Tick(double time);
	void Draw();

private:
	double rotation;

	const double rotation_speed;
	const double star_radius;
};

