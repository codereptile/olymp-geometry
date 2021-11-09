#ifndef OLYMP_GEOMETRY_OLYMP_GEOMETRY_H
#define OLYMP_GEOMETRY_OLYMP_GEOMETRY_H

#include <iostream>
#include <cmath>

namespace olymp_geometry {
    const long double kEps = 0.00000001;

    class Vector {
    public:
        long double x_, y_;

        Vector();

        Vector(long double x, long double y);

        Vector(std::istream &in);
        // Functions:

        long double Length() const;

        Vector GetPerpendicular() const;

        // OPERATORS:

        void operator+=(const Vector &other);

        void operator+=(Vector &&other);

        void operator-=(const Vector &other);

        void operator-=(Vector &&other);

        friend Vector operator+(const Vector &a, const Vector &b);

        friend Vector operator+(const Vector &a, Vector &&b);

        friend Vector operator+(Vector &&a, Vector &&b);

        friend Vector operator-(const Vector &a, const Vector &b);

        friend Vector operator-(const Vector &a, Vector &&b);

        friend Vector operator-(Vector &&a, Vector &&b);

        friend std::istream &operator>>(std::istream &in, Vector &v);

        friend std::istream &operator>>(std::istream &in, Vector &&v);

        friend std::ostream &operator<<(std::ostream &out, const Vector &v);

        friend std::ostream &operator<<(std::ostream &out, Vector &&v);

        friend bool operator==(const Vector &a, const Vector &b);

        friend bool operator==(const Vector &a, Vector &&b);

        friend bool operator==(Vector &&a, Vector &&b);
    };

    class Line {
    public:
        long double A_, B_, C_;

        Line();

        Line(long double a, long double b, long double c);

        Line(std::istream &in);

        Line(const Vector &a, const Vector &b);

        Vector GetNormal() const;

        friend std::istream &operator>>(std::istream &in, Line &line);

        friend std::istream &operator>>(std::istream &in, Line &&line);

        friend std::ostream &operator<<(std::ostream &out, const Line &line);

        friend std::ostream &operator<<(std::ostream &out, Line &&line);

        friend bool operator==(const Line &a, const Line &b);

        friend bool operator==(const Line &a, Line &&b);

        friend bool operator==(Line &&a, Line &&b);
    };

    class Beam {
    public:
        Vector a_, b_;

        Beam();

        Beam(const Vector &a, const Vector &b);

        Beam(std::istream &in);

        friend std::istream &operator>>(std::istream &in, Beam &v);

        friend std::istream &operator>>(std::istream &in, Beam &&v);
    };

    class Segment {
    public:
        Vector a_, b_;

        Segment();

        Segment(const Vector &a, const Vector &b);

        Segment(std::istream &in);

        friend std::istream &operator>>(std::istream &in, Segment &v);

        friend std::istream &operator>>(std::istream &in, Segment &&v);
    };

    /*!
    \defgroup vector_multiplication Умножение векторов
    \brief Предоставляет скалярное и векторное умножение над векторами.
    */
    ///@{
    ///@}

    /*!
    \defgroup scalar_vector_multiplication Скалярное умножение векторов
    \ingroup vector_multiplication
    \brief Скалярное умножение.
    */
    ///@{
    long double ScalarMultiplication(const Vector &a, const Vector &b);

    long double ScalarMultiplication(const Vector &a, Vector &&b);

    long double ScalarMultiplication(Vector &&a, Vector &&b);
    ///@}

    /*!
    \defgroup vector_vector_multiplication Векторное умножение векторов
    \ingroup vector_multiplication
    \brief Векторное умножение.
    */
    ///@{
    long double VectorMultiplication(const Vector &a, const Vector &b);

    long double VectorMultiplication(const Vector &a, Vector &&b);

    long double VectorMultiplication(Vector &&a, const Vector &b);

    long double VectorMultiplication(Vector &&a, Vector &&b);
    ///@}

    /*!
    \defgroup angles Работа с углами
    \brief Модуль содержит различные методы для работы с углами.
    */
    ///@{

    /*!
    Даёт косинус угла между векторами через скалярное умножение.
    \param[in] a Первый вектор
    \param[in] b Второй вектор
    \return Косинус угла между a и b
    */
    long double AngleCos(const Vector &a, const Vector &b);

    long double AngleCos(const Vector &a, Vector &&b);

    long double AngleCos(Vector &&a, Vector &&b);

    long double Angle(const Vector &a, const Vector &b);

    long double Angle(const Vector &a, Vector &&b);

    long double Angle(Vector &&a, Vector &&b);

    /*!
    Переводит угол из градусов в радианы.
    \param[in] x Значение угла в градусах
    \return Значение угла в радианах
    */

    long double DegToRad(long double x);

    /*!
    Переводит угол из радианов в градусы.
    \param[in] x Значение угла в радианах
    \return Значение угла в градусах
    */
    long double RadToDeg(long double x);

    /*!
    Проверяет, находится ли вектор m между векторами a и b.
    \param[in] a Первый вектор задающий угол - a
    \param[in] b Второй вектор задающий угол - b
    \param[in] m Проверяемый вектор - m
    \return true, если m находится между a и b, false в ином случае
    */

    bool IsBetween(const Vector &a, const Vector &b, const Vector &m);

    bool IsBetween(const Vector &a, const Vector &b, Vector &&m);

    bool IsBetween(const Vector &a, Vector &&b, const Vector &m);

    bool IsBetween(const Vector &a, Vector &&b, Vector &&m);

    bool IsBetween(Vector &&a, const Vector &b, const Vector &m);

    bool IsBetween(Vector &&a, const Vector &b, Vector &&m);

    bool IsBetween(Vector &&a, Vector &&b, const Vector &m);

    bool IsBetween(Vector &&a, Vector &&b, Vector &&m);

    ///@}

    bool LiesOn(const Segment &segment, const Vector &v);

    bool LiesOn(const Segment &segment, Vector &&v);

    bool LiesOn(Segment &&segment, const Vector &v);

    bool LiesOn(Segment &&segment, Vector &&v);

    long double Dist(const Vector &a, const Vector &b);

    long double Dist(const Vector &a, Vector &b);

    long double Dist(Vector &&a, Vector &&b);

    long double Dist(const Line &line, const Vector &v);

    long double Dist(Line &&line, const Vector &v);

    long double Dist(const Line &line, Vector &&v);

    long double Dist(Line &&line, Vector &&v);

    long double Dist(const Beam &beam, const Vector &v);

    long double Dist(const Beam &beam, Vector &&v);

    long double Dist(Beam &&beam, const Vector &v);

    long double Dist(Beam &&beam, Vector &&v);

    long double Dist(const Segment &segment, const Vector &v);

    long double Dist(const Segment &segment, Vector &&v);

    long double Dist(Segment &&segment, const Vector &v);

    long double Dist(Segment &&segment, Vector &&v);

    bool OnSameSideEq(const Line &line, const Vector &a, const Vector &b);

    bool OnSameSideEq(const Line &line, const Vector &a, Vector &&b);

    bool OnSameSideEq(const Line &line, Vector &&a, Vector &&b);

    bool OnSameSideEq(Line &&line, const Vector &a, const Vector &b);

    bool OnSameSideEq(Line &&line, const Vector &a, Vector &&b);

    bool OnSameSideEq(Line &&line, Vector &&a, Vector &&b);

    bool OnSameSide(const Line &line, const Vector &a, const Vector &b);

    bool OnSameSide(const Line &line, const Vector &a, Vector &&b);

    bool OnSameSide(const Line &line, Vector &&a, Vector &&b);

    bool OnSameSide(Line &&line, const Vector &a, const Vector &b);

    bool OnSameSide(Line &&line, const Vector &a, Vector &&b);

    bool OnSameSide(Line &&line, Vector &&a, Vector &&b);

    bool Intersect(const Segment &s1, const Segment &s2);

    bool Intersect(const Segment &s1, Segment &&s2);

    bool Intersect(Segment &&s1, Segment &&s2);
}


#endif //OLYMP_GEOMETRY_OLYMP_GEOMETRY_H