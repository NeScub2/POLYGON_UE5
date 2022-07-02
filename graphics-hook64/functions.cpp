#include "functions.h"
#include "sigScaner.h"
#include <cmath>
#include <algorithm> 
void CalcAngle(FVector src, FVector dst, FRotator* angles)
{
	double delta[3] = { (src.X- dst.X), (src.Y - dst.Y), (src.Z - dst.Z) };
	float hyp = sqrt(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
	angles->Pitch = (float)(asinf(delta[2] / hyp) * 57.295779513082f);
	angles->Yaw = (float)(atanf(delta[1] / delta[0]) * 57.295779513082f);
	angles->Roll = 0.0f;
	if (delta[0] >= 0.0) { angles->Yaw += 180.0f; }
}
void normalizeAngles(FVector2D angles)
{
	while (angles.X > 88.f)
		angles.X -= 180.f;

	while (angles.X < -88.f)
		angles.X += 180.f;

	while (angles.Y > 180.f)
		angles.Y -= 360.f;

	while (angles.Y < -180.f)
		angles.Y += 360.f;
}
void clampAngles(FVector2D angles)
{
	if (angles.Y > 89.0)
		angles.Y = 89.0;

	if (angles.Y < -89.0)
		angles.Y = -89.0;

	if (angles.Y > 180.0)
		angles.Y = 180.0;

	if (angles.Y < -180.0)
		angles.Y = -180.0;
}
FVector2D functions::GetaimAnglesTo(FVector localPosition, FVector target)
{
	FVector dPosition = localPosition - target;
	double hypotenuse = sqrt(dPosition.X * dPosition.X + dPosition.Y * dPosition.Y);
	FVector a = { atan2f(dPosition.Z, hypotenuse) * 57.295779513082f, atanf(dPosition.Y / dPosition.X) * 57.295779513082f, 0 };
	if (dPosition.X >= 0.f)
		a.Y += 180.0f;
	FVector2D aimAngles;
	aimAngles.X = a.X;     // up and down
	aimAngles.Y = a.Y;      // left and right
	normalizeAngles(aimAngles);
	clampAngles(aimAngles);
	return aimAngles;
}
