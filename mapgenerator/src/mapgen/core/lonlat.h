#pragma once

namespace ikowapi
{
struct Vector2;

struct LonLat
{
    double m_Lon;
    double m_Lat;
	
	Vector2 operator-(const LonLat& other) const
	{
		return Vector2(m_Lat - other.m_Lat, m_Lon - other.m_Lon);		
	}

	LonLat& operator+=(const Vector2& v)
	{
		m_Lat += v.m_X;
		m_Lon += v.m_Y;
		return *this;
	}

	LonLat operator+(const Vector2& v) const
	{
		LonLat l(*this);
		l += v;
		return l;
	}
};

struct Vector2
{
	Vector2(const LonLat& start, const LonLat& end)
	{
		m_X = end.m_Lat - start.m_Lat;
		m_Y = end.m_Lat - start.m_Lat;
	}

	Vector2(double x, double y)
		: m_X(x)
		, m_Y(y)
	{
	}

	Vector2()
		: m_X(0)
		, m_Y(0)
	{
	}

	Vector2(const Vector2&) = default;
	Vector2& operator=(const Vector2&) = default;

	double length() const
	{
		return sqrt(m_X*m_X + m_Y*m_Y);
	}

	void normalize()
	{
		auto len = length();
		m_X /= len;
		m_Y /= len;
	}

	Vector2& operator+=(const Vector2& other)
	{
		m_X += other.m_X;
		m_Y += other.m_Y;
		return *this;
	}

	Vector2 operator*(double value) const
	{
		Vector2 v(*this);
		v *= value;
		return v;
	}

	Vector2 operator/(double value) const
	{
		Vector2 v(*this);
		v /= value;
		return v;
	}

	Vector2& operator-=(const Vector2& other)
	{
		m_X -= other.m_X;
		m_Y -= other.m_Y;
		return *this;
	}

	Vector2 operator+(const Vector2& other) const
	{
		Vector2 v(*this);
		v += other;
		return v;
	}

	Vector2 operator-(const Vector2& other) const
	{
		Vector2 v(*this);
		v -= other;
		return v;
	}

	Vector2& operator*=(double value)
	{
		m_X *= value;
		m_Y *= value;
		return *this;
	}

	Vector2& operator/=(double value)
	{
		m_X /= value;
		m_Y /= value;
	}

	Vector2 getPerpendicularLeft() const
	{
		return Vector2(-m_Y, m_X);
	}

	Vector2 getPerpendicularRight() const
	{
		return Vector2(m_Y, -m_X);
	}
	double m_X;
	double m_Y;
};

}