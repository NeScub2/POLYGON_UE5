#pragma once
#include <cmath>
#include <unordered_set>
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include "Addrs.h"
struct FVector
{
	double                                              X;                                                         // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	double                                              Y;                                                         // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	double                                              Z;                                                         // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)


	inline FVector() : X(0), Y(0), Z(0) {}

	inline FVector(double x, double y, double z) : X(x), Y(y), Z(z) {}

	inline FVector operator + (const FVector& other) const { return FVector(X + other.X, Y + other.Y, Z + other.Z); }

	inline FVector operator - (const FVector& other) const { return FVector(X - other.X, Y - other.Y, Z - other.Z); }

	inline FVector operator * (double scalar) const { return FVector(X * scalar, Y * scalar, Z * scalar); }

	inline FVector operator * (const FVector& other) const { return FVector(X * other.X, Y * other.Y, Z * other.Z); }

	inline FVector operator / (double scalar) const { return FVector(X / scalar, Y / scalar, Z / scalar); }

	inline FVector operator / (const FVector& other) const { return FVector(X / other.X, Y / other.Y, Z / other.Z); }

	inline FVector& operator=  (const FVector& other) { X = other.X; Y = other.Y; Z = other.Z; return *this; }

	inline FVector& operator+= (const FVector& other) { X += other.X; Y += other.Y; Z += other.Z; return *this; }

	inline FVector& operator-= (const FVector& other) { X -= other.X; Y -= other.Y; Z -= other.Z; return *this; }

	inline FVector& operator*= (const double other) { X *= other; Y *= other; Z *= other; return *this; }

	inline double Dot(const FVector& b) const { return (X * b.X) + (Y * b.Y) + (Z * b.Z); }

	inline double MagnitudeSqr() const { return Dot(*this); }

	inline double Magnitude() const { return std::sqrtf(MagnitudeSqr()); }

	inline FVector Unit() const
	{
		const double fMagnitude = Magnitude();
		return FVector(X / fMagnitude, Y / fMagnitude, Z / fMagnitude);
	}

	inline int dot_product(FVector vector_a, FVector vector_b) const
	{
		int product = 0;
	
			product =( product + vector_a.X * vector_b.Y);
			product =( product + vector_a.Y * vector_b.Y);
			product =( product + vector_a.Z * vector_b.Z);
		return product;
	}

	friend bool operator==(const FVector& first, const FVector& second) { return first.X == second.X && first.Y == second.Y && first.Z == second.Z; }

	friend bool operator!=(const FVector& first, const FVector& second) { return !(first == second); }

};
struct FRotator
{
	float                                              Pitch;                                                     // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                              Yaw;                                                       // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                              Roll;                                                      // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)


	inline FRotator() : Pitch(0), Yaw(0), Roll(0) {}

	inline FRotator(float pitch, float yaw, float roll) : Pitch(pitch), Yaw(yaw), Roll(roll) {}

	inline float Size() { return sqrt(Pitch * Pitch + Yaw * Yaw + Roll * Roll); }

	inline FRotator Clamp()
	{
		FRotator r = { Pitch, Yaw, Roll };
		if (r.Yaw > 180.f)
			r.Yaw -= 360.f;
		else if (r.Yaw < -180.f)
			r.Yaw += 360.f;

		if (r.Pitch > 180.f)
			r.Pitch -= 360.f;
		else if (r.Pitch < -180.f)
			r.Pitch += 360.f;

		if (r.Pitch < -89.f)
			r.Pitch = -89.f;
		else if (r.Pitch > 89.f)
			r.Pitch = 89.f;

		r.Roll = 0.f;
		return r;
	}


	inline FRotator operator + (const FRotator& other) const { return FRotator(Pitch + other.Pitch, Yaw + other.Yaw, Roll + other.Roll); }

	inline FRotator operator - (const FRotator& other) const { return FRotator(Pitch - other.Pitch, Yaw - other.Yaw, Roll - other.Roll); }

	inline FRotator operator * (float scalar) const { return FRotator(Pitch * scalar, Yaw * scalar, Roll * scalar); }

	inline FRotator operator * (const FRotator& other) const { return FRotator(Pitch * other.Pitch, Yaw * other.Yaw, Roll * other.Roll); }

	inline FRotator operator / (float scalar) const { return FRotator(Pitch / scalar, Yaw / scalar, Roll / scalar); }

	inline FRotator operator / (const FRotator& other) const { return FRotator(Pitch / other.Pitch, Yaw / other.Yaw, Roll / other.Roll); }

	inline FRotator& operator=  (const FRotator& other) { Pitch = other.Pitch; Yaw = other.Yaw; Roll = other.Roll; return *this; }

	inline FRotator& operator+= (const FRotator& other) { Pitch += other.Pitch; Yaw += other.Yaw; Roll += other.Roll; return *this; }

	inline FRotator& operator-= (const FRotator& other) { Pitch -= other.Pitch; Yaw -= other.Yaw; Roll -= other.Roll; return *this; }

	inline FRotator& operator*= (const float other) { Pitch *= other; Yaw *= other; Roll *= other; return *this; }

	friend bool operator==(const FRotator& first, const FRotator& second) { return first.Pitch == second.Pitch && first.Yaw == second.Yaw && first.Roll == second.Roll; }

};
struct FVector2D
{
	double                                              X;                                                         // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	double                                              Y;                                                         // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)


	inline FVector2D() : X(0), Y(0) {}

	inline FVector2D(double x, double y) : X(x), Y(y) {}

	inline FVector2D operator + (const FVector2D& other) const { return FVector2D(X + other.X, Y + other.Y); }

	inline FVector2D operator - (const FVector2D& other) const { return FVector2D(X - other.X, Y - other.Y); }

	inline FVector2D operator * (double scalar) const { return FVector2D(X * scalar, Y * scalar); }

	inline FVector2D operator * (const FVector2D& other) const { return FVector2D(X * other.X, Y * other.Y); }

	inline FVector2D operator / (double scalar) const { return FVector2D(X / scalar, Y / scalar); }

	inline FVector2D operator / (const FVector2D& other) const { return FVector2D(X / other.X, Y / other.Y); }

	inline FVector2D& operator=  (const FVector2D& other) { X = other.X; Y = other.Y; return *this; }

	inline FVector2D& operator+= (const FVector2D& other) { X += other.X; Y += other.Y; return *this; }

	inline FVector2D& operator-= (const FVector2D& other) { X -= other.X; Y -= other.Y; return *this; }

	inline FVector2D& operator*= (const double other) { X *= other; Y *= other; return *this; }

};
class FMinimalViewInfo
{
public:
	FVector Location; // 0x00(0x0c)
	FVector Rotation; // 0x0c(0x0c)
	float FOV; // 0x18(0x04)
	float DesiredFOV; // 0x1c(0x04)
	float OrthoWidth; // 0x20(0x04)
	float OrthoNearClipPlane; // 0x24(0x04)
	float OrthoFarClipPlane; // 0x28(0x04)
	float AspectRatio; // 0x2c(0x04)
};
class FCameraCacheEntry
{
public:
	float Timestamp; // 0x00(0x04)
	char pad_4[0xc]; // 0x04(0x0c)
	FMinimalViewInfo POV; // 0x10(0x5e0)
};
struct FPlane : public FVector
{
	double  W;                                                         // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

};
struct FMatrix
{
	struct FPlane                                      XPlane;                                                    // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPlane                                      YPlane;                                                    // 0x0010(0x0010) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPlane                                      ZPlane;                                                    // 0x0020(0x0010) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPlane                                      WPlane;                                                    // 0x0030(0x0010) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
struct FLinearColor
{
    float                                              R;                                                         // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
    float                                              G;                                                         // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
    float                                              B;                                                         // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
    float                                              A;                                                         // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)


    inline FLinearColor()
        : R(0), G(0), B(0), A(0)
    { }

    inline FLinearColor(float r, float g, float b, float a)
        : R(r),
        G(g),
        B(b),
        A(a)
    { }

};
template<class T>
struct TArray
{
private:
	T* Data;
	int32_t Count;
	int32_t Max;

	friend struct FString;

public:
	TArray()
	{
		Data = nullptr;
		Max = 0;
		Count = 0;
	}

	int Num() const
	{
		return Count;
	}

	T& operator[](int i)
	{
		return Data[i];
	}

	const T& operator[](int i) const
	{
		return Data[i];
	}

	bool IsValidIndex(int i) const
	{
		return i < Num();
	}
};
struct FString : public TArray<wchar_t>
{
	FString() = default;

	explicit FString(const wchar_t* other)
	{
		Max = Count = *other ? std::wcslen(other) + 1 : 0;

		if (Count)
		{
			Data = const_cast<wchar_t*>(other);
		}
	};

	inline bool IsValid() const
	{
		return Data != nullptr;
	}

	inline const wchar_t* cw_str() const
	{
		return Data;
	}

	inline const char* c_str() const
	{
		return (const char*)Data;
	}

	std::string ToString() const
	{
		size_t length = std::wcslen(Data);
		std::string str(length, '\0');
		std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

		return str;
	}

	std::wstring ToWString() const
	{
		std::wstring str(Data);
		return str;
	}
};

struct FKey
{
	struct FName* KeyName;                                                   // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	unsigned char                                      UnknownData_T32I[0x10];                                    // 0x0008(0x0010) MISSED OFFSET (PADDING)

};
class AHud
{
public:
	inline void DrawLine(FVector2D  StartScreen, FVector2D EndScreen, float LineThickness, FLinearColor LineColor) {
		return reinterpret_cast<void(__fastcall*)(AHud * _this, float StartScreenX, float StartScreenY, float EndScreenX, float EndScreenY, FLinearColor LineColor, float LineThickness)>(Addrs::HUDDrawLine)(this, StartScreen.X, StartScreen.Y, EndScreen.X, EndScreen.Y, LineColor, LineThickness);
	}
	inline void HDrawText(FString Text, FLinearColor TextColor, float ScreenX, float ScreenY, uintptr_t* Font, float Scale, bool bScalePosition) {
		return reinterpret_cast<void(__fastcall*)(AHud * _this, FString Text, FLinearColor TextColor, float ScreenX, float ScreenY, uintptr_t * Font, float Scale, bool bScalePosition)>(Addrs::HUDDrawText)(this, Text, TextColor, ScreenX, ScreenY, Font, Scale, bScalePosition);
	}
	void DrawRect( float x1, float y1, float x2, float y2, FLinearColor color, float linesize)
	{
		this->DrawLine( { x1, y1 }, { x2, y1 }, linesize, color);
		this->DrawLine( { x1, y1 }, { x1, y2 }, linesize, color);
		this->DrawLine( { x2, y2 }, { x2, y1 }, linesize, color);
		this->DrawLine( { x2, y2 }, { x1, y2 }, linesize, color);
	}
	void DrawCircle(FVector2D pos, int radius, int numSides, FLinearColor Color)
	{
		float PI = 3.1415927f;

		float Step = PI * 2.0 / numSides;
		int Count = 0;
		FVector2D V[128];
		for (float a = 0; a < PI * 2.0; a += Step) {
			float X1 = radius * cos(a) + pos.X;
			float Y1 = radius * sin(a) + pos.Y;
			float X2 = radius * cos(a + Step) + pos.X;
			float Y2 = radius * sin(a + Step) + pos.Y;
			V[Count].X = X1;
			V[Count].Y = Y1;
			V[Count + 1].X = X2;
			V[Count + 1].Y = Y2;
			this->DrawLine( { V[Count].X, V[Count].Y }, { X2, Y2 }, 1.0f, Color);
		}
	}
};
class UCanvas 
{
public:
	float a;
	float                                              OrgX;                                                      // 0x0028(0x0004) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                              OrgY;                                                      // 0x002C(0x0004) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                              ClipX;                                                     // 0x0030(0x0004) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                              ClipY;                                                     // 0x0034(0x0004) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FColor*                                      DrawColor;                                                 // 0x0038(0x0004) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	unsigned char                                      bCenterX : 1;                                              // 0x003C(0x0001) BIT_FIELD (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	unsigned char                                      bCenterY : 1;                                              // 0x003C(0x0001) BIT_FIELD (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	unsigned char                                      bNoSmooth : 1;                                             // 0x003C(0x0001) BIT_FIELD (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	unsigned char                                      UnknownData_MLYB[0x3];                                     // 0x003D(0x0003) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
	int                                                SizeX;                                                     // 0x0040(0x0004) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int                                                SizeY;                                                     // 0x0044(0x0004) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	unsigned char                                      UnknownData_B9I2[0x8];                                     // 0x0048(0x0008) MISSED OFFSET (FIX SPACE BETWEEN PREVIOUS PROPERTY)
	struct FPlane                                      ColorModulate;                                             // 0x0050(0x0010) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D* DefaultTexture;                                            // 0x0060(0x0008) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D* GradientTexture0;                                          // 0x0068(0x0008) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UReporterGraph* ReporterGraph;                                             // 0x0070(0x0008) (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	unsigned char                                      UnknownData_E8YA[0x258];                                   // 0x0078(0x0258) MISSED OFFSET (PADDING)


	inline void K2DrawLine( FVector2D ScreenPositionA, FVector2D ScreenPositionB, float Thickness, FLinearColor RenderColor) {
			return reinterpret_cast<void(__fastcall*)(UCanvas*  _this, FVector2D ScreenPositionA,FVector2D  ScreenPositionB,float Thickness,FLinearColor RenderColor)>(Addrs::K2DrawLine)(this, ScreenPositionA, ScreenPositionB, Thickness,RenderColor);
	}
	inline void K2DrawText(uintptr_t* RenderFont,  FString RenderText,  FVector2D ScreenPosition,  FVector2D Scale,  FLinearColor RenderColor, float Kerning,  FLinearColor ShadowColor,  FVector2D ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined,  FLinearColor OutlineColor)
	{
		return reinterpret_cast<void(__fastcall*)(UCanvas * _this, uintptr_t * RenderFont, FString RenderText, FVector2D ScreenPosition, FVector2D Scale, FLinearColor RenderColor, float Kerning, FLinearColor ShadowColor, FVector2D ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, FLinearColor OutlineColor)>(Addrs::K2DrawText)(this, RenderFont, RenderText, ScreenPosition,Scale,RenderColor,Kerning,ShadowColor,ShadowOffset,bCenterX,bCenterY,bOutlined,OutlineColor);
	}
	inline void K2DrawCircle(FVector2D pos, int radius, int numSides, FLinearColor Color)
	{
		float PI = 3.1415927f;

		float Step = PI * 2.0 / numSides;
		int Count = 0;
		FVector2D V[128];
		for (float a = 0; a < PI * 2.0; a += Step) {
			float X1 = radius * cos(a) + pos.X;
			float Y1 = radius * sin(a) + pos.Y;
			float X2 = radius * cos(a + Step) + pos.X;
			float Y2 = radius * sin(a + Step) + pos.Y;
			V[Count].X = X1;
			V[Count].Y = Y1;
			V[Count + 1].X = X2;
			V[Count + 1].Y = Y2;
			//Draw_Line(FVector2D{ pos.X, pos.Y }, FVector2D{ X2, Y2 }, 1.0f, Color); // Points from Centre to ends of circle
			this->K2DrawLine({ V[Count].X, V[Count].Y }, { X2, Y2 }, 1.0f, Color);// Circle Around
		}
	}
	inline void K2DrawRect( float x1, float y1, float x2, float y2, FLinearColor color, float linesize)
	{
		this->K2DrawLine( { x1, y1 }, { x2, y1 }, linesize, color);
		this->K2DrawLine( { x1, y1 }, { x1, y2 }, linesize, color);
		this->K2DrawLine( { x2, y2 }, { x2, y1 }, linesize, color);
		this->K2DrawLine( { x2, y2 }, { x1, y2 }, linesize, color);
	}
	
};