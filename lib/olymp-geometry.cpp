#include "olymp-geometry.h"

namespace olymp_geometry {
    Vector::Vector() {
        x_ = 0;
        y_ = 0;
    }

    Vector::Vector(long double x, long double y) {
        x_ = x;
        y_ = y;
    }

    Vector::Vector(std::istream &in) {
        in >> x_ >> y_;
    }

    long double Vector::Length() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    Vector Vector::GetPerpendicular() const {
        return {y_, -x_};
    }

    void Vector::operator+=(const Vector &other) {
        x_ += other.x_;
        y_ += other.y_;
    }

    void Vector::operator+=(Vector &&other) {
        x_ += other.x_;
        y_ += other.y_;
    }

    void Vector::operator-=(const Vector &other) {
        x_ -= other.x_;
        y_ -= other.y_;
    }

    void Vector::operator-=(Vector &&other) {
        x_ -= other.x_;
        y_ -= other.y_;
    }

    Vector operator+(const Vector &a, const Vector &b) {
        return {a.x_ + b.x_, a.y_ + b.y_};
    }

    Vector operator+(const Vector &a, Vector &&b) {
        return {a.x_ + b.x_, a.y_ + b.y_};
    }

    Vector operator+(Vector &&a, Vector &&b) {
        return {a.x_ + b.x_, a.y_ + b.y_};
    }

    Vector operator-(const Vector &a, const Vector &b) {
        return {a.x_ - b.x_, a.y_ - b.y_};
    }

    Vector operator-(const Vector &a, Vector &&b) {
        return {a.x_ - b.x_, a.y_ - b.y_};
    }

    Vector operator-(Vector &&a, Vector &&b) {
        return {a.x_ - b.x_, a.y_ - b.y_};
    }

    std::istream &operator>>(std::istream &in, Vector &v) {
        in >> v.x_ >> v.y_;
        return in;
    }

    std::istream &operator>>(std::istream &in, Vector &&v) {
        in >> v.x_ >> v.y_;
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const Vector &v) {
        out << v.x_ << " " << v.y_;
        return out;
    }

    std::ostream &operator<<(std::ostream &out, Vector &&v) {
        out << v.x_ << " " << v.y_;
        return out;
    }

    bool operator==(const Vector &a, const Vector &b) {
        return (std::fabs(b.x_ - a.x_) < kEps && std::fabs(b.y_ - a.y_) < kEps);
    }

    bool operator==(const Vector &a, Vector &&b) {
        return (std::fabs(b.x_ - a.x_) < kEps && std::fabs(b.y_ - a.y_) < kEps);
    }

    bool operator==(Vector &&a, Vector &&b) {
        return (std::fabs(b.x_ - a.x_) < kEps && std::fabs(b.y_ - a.y_) < kEps);
    }

    Line::Line() {
        A_ = 1;
        B_ = -1;
        C_ = 0;
    }

    Line::Line(long double a, long double b, long double c) {
        A_ = a;
        B_ = b;
        C_ = c;
    }

    Line::Line(std::istream &in) {
        in >> A_ >> B_ >> C_;
    }

    Line::Line(const Vector &a, const Vector &b) {
        Vector direction = b - a;
        Vector norm = direction.GetPerpendicular();
        A_ = norm.x_;
        B_ = norm.y_;
        C_ = -(A_ * a.x_ + B_ * a.y_);
    }

    Vector Line::GetNormal() const {
        return Vector(A_, B_);
    }

    std::istream &operator>>(std::istream &in, Line &line) {
        in >> line.A_ >> line.B_ >> line.C_;
        return in;
    }

    std::istream &operator>>(std::istream &in, Line &&line) {
        in >> line.A_ >> line.B_ >> line.C_;
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const Line &line) {
        out << line.A_ << " " << line.B_ << " " << line.C_;
        return out;
    }

    std::ostream &operator<<(std::ostream &out, Line &&line) {
        out << line.A_ << " " << line.B_ << " " << line.C_;
        return out;
    }

    bool operator==(const Line &a, const Line &b) {
        return (std::fabs(a.A_ * b.B_ - b.A_ * a.B_) < kEps && std::fabs(a.B_ * b.C_ - b.B_ * a.C_) < kEps);
    }

    bool operator==(const Line &a, Line &&b) {
        return (std::fabs(a.A_ * b.B_ - b.A_ * a.B_) < kEps && std::fabs(a.B_ * b.C_ - b.B_ * a.C_) < kEps);
    }

    bool operator==(Line &&a, Line &&b) {
        return (std::fabs(a.A_ * b.B_ - b.A_ * a.B_) < kEps && std::fabs(a.B_ * b.C_ - b.B_ * a.C_) < kEps);
    }

    Beam::Beam() {
        a_ = {0, 0};
        b_ = {1, 1};
    }

    Beam::Beam(const Vector &a, const Vector &b) {
        a_ = a;
        b_ = b;
    }

    Beam::Beam(std::istream &in) {
        std::cin >> a_ >> b_;
    }

    std::istream &operator>>(std::istream &in, Beam &v) {
        in >> v.a_ >> v.b_;
        return in;
    }

    std::istream &operator>>(std::istream &in, Beam &&v) {
        in >> v.a_ >> v.b_;
        return in;
    }

    Segment::Segment() {
        a_ = {0, 0};
        b_ = {1, 1};
    }

    Segment::Segment(const Vector &a, const Vector &b) {
        a_ = a;
        b_ = b;
    }

    Segment::Segment(std::istream &in) {
        std::cin >> a_ >> b_;
    }

    std::istream &operator>>(std::istream &in, Segment &v) {
        in >> v.a_ >> v.b_;
        return in;
    }

    std::istream &operator>>(std::istream &in, Segment &&v) {
        in >> v.a_ >> v.b_;
        return in;
    }

    long double ScalarMultiplication(const Vector &a, const Vector &b) {
        return a.x_ * b.x_ + a.y_ * b.y_;
    }

    long double ScalarMultiplication(const Vector &a, Vector &&b) {
        return a.x_ * b.x_ + a.y_ * b.y_;
    }

    long double ScalarMultiplication(Vector &&a, Vector &&b) {
        return a.x_ * b.x_ + a.y_ * b.y_;
    }

    long double VectorMultiplication(const Vector &a, const Vector &b) {
        return a.x_ * b.y_ - a.y_ * b.x_;
    }

    long double VectorMultiplication(const Vector &a, Vector &&b) {
        return a.x_ * b.y_ - a.y_ * b.x_;
    }

    long double VectorMultiplication(Vector &&a, const Vector &b) {
        return a.x_ * b.y_ - a.y_ * b.x_;
    }

    long double VectorMultiplication(Vector &&a, Vector &&b) {
        return a.x_ * b.y_ - a.y_ * b.x_;
    }

    long double AngleCos(const Vector &a, const Vector &b) {
        return ScalarMultiplication(a, b) / a.Length() / b.Length();
    }

    long double AngleCos(const Vector &a, Vector &&b) {
        return ScalarMultiplication(a, b) / a.Length() / b.Length();
    }

    long double AngleCos(Vector &&a, Vector &&b) {
        return ScalarMultiplication(a, b) / a.Length() / b.Length();
    }

    long double Angle(const Vector &a, const Vector &b) {
        return std::acos(AngleCos(a, b));
    }

    long double Angle(const Vector &a, Vector &&b) {
        return std::acos(AngleCos(a, b));
    }

    long double Angle(Vector &&a, Vector &&b) {
        return std::acos(AngleCos(a, b));
    }

    long double DegToRad(long double x) {
        return x * M_PI / 180.0;
    }

    long double RadToDeg(long double x) {
        return x * 180.0 / M_PI;
    }

    bool LiesOn(const Segment &segment, const Vector &v) {
        if (segment.a_ == v || segment.b_ == v) {
            return true;
        } else if (segment.a_ == segment.b_) {
            return false;
        }

        Vector alpha1 = segment.b_ - segment.a_;
        Vector beta1 = v - segment.a_;
        Vector alpha2 = segment.a_ - segment.b_;
        Vector beta2 = v - segment.b_;
        if (std::fabs(AngleCos(alpha1, beta1) - 1.0) < kEps && std::fabs(AngleCos(alpha2, beta2) - 1.0) < kEps) {
            return true;
        } else {
            return false;
        }
    }

    bool LiesOn(const Segment &segment, Vector &&v) {
        if (segment.a_ == v || segment.b_ == v) {
            return true;
        } else if (segment.a_ == segment.b_) {
            return false;
        }

        Vector alpha1 = segment.b_ - segment.a_;
        Vector beta1 = v - segment.a_;
        Vector alpha2 = segment.a_ - segment.b_;
        Vector beta2 = v - segment.b_;
        if (std::fabs(AngleCos(alpha1, beta1) - 1.0) < kEps && std::fabs(AngleCos(alpha2, beta2) - 1.0) < kEps) {
            return true;
        } else {
            return false;
        }
    }

    bool LiesOn(Segment &&segment, const Vector &v) {
        if (segment.a_ == v || segment.b_ == v) {
            return true;
        } else if (segment.a_ == segment.b_) {
            return false;
        }

        Vector alpha1 = segment.b_ - segment.a_;
        Vector beta1 = v - segment.a_;
        Vector alpha2 = segment.a_ - segment.b_;
        Vector beta2 = v - segment.b_;
        if (std::fabs(AngleCos(alpha1, beta1) - 1.0) < kEps && std::fabs(AngleCos(alpha2, beta2) - 1.0) < kEps) {
            return true;
        } else {
            return false;
        }
    }

    bool LiesOn(Segment &&segment, Vector &&v) {
        if (segment.a_ == v || segment.b_ == v) {
            return true;
        } else if (segment.a_ == segment.b_) {
            return false;
        }

        Vector alpha1 = segment.b_ - segment.a_;
        Vector beta1 = v - segment.a_;
        Vector alpha2 = segment.a_ - segment.b_;
        Vector beta2 = v - segment.b_;
        if (std::fabs(AngleCos(alpha1, beta1) - 1.0) < kEps && std::fabs(AngleCos(alpha2, beta2) - 1.0) < kEps) {
            return true;
        } else {
            return false;
        }
    }

    long double Dist(const Vector &a, const Vector &b) {
        return (b - a).Length();
    }

    long double Dist(const Vector &a, Vector &b) {
        return (b - a).Length();
    }

    long double Dist(Vector &&a, Vector &&b) {
        return (b - a).Length();
    }

    long double Dist(const Line &line, const Vector &v) {
        return std::fabs(line.A_ * v.x_ + line.B_ * v.y_ + line.C_) / line.GetNormal().Length();
    }

    long double Dist(Line &&line, const Vector &v) {
        return std::fabs(line.A_ * v.x_ + line.B_ * v.y_ + line.C_) / line.GetNormal().Length();
    }

    long double Dist(const Line &line, Vector &&v) {
        return std::fabs(line.A_ * v.x_ + line.B_ * v.y_ + line.C_) / line.GetNormal().Length();
    }

    long double Dist(Line &&line, Vector &&v) {
        return std::fabs(line.A_ * v.x_ + line.B_ * v.y_ + line.C_) / line.GetNormal().Length();
    }

    long double Dist(const Beam &beam, const Vector &v) {
        Vector alpha = beam.b_ - beam.a_;
        Vector beta = v - beam.a_;
        if (AngleCos(alpha, beta) >= 0) {
            return Dist(Line(beam.a_, beam.b_), v);
        } else {
            return Dist(beam.a_, v);
        }
    }

    long double Dist(const Beam &beam, Vector &&v) {
        Vector alpha = beam.b_ - beam.a_;
        Vector beta = v - beam.a_;
        if (AngleCos(alpha, beta) >= 0) {
            return Dist(Line(beam.a_, beam.b_), v);
        } else {
            return Dist(beam.a_, v);
        }
    }

    long double Dist(Beam &&beam, const Vector &v) {
        Vector alpha = beam.b_ - beam.a_;
        Vector beta = v - beam.a_;
        if (AngleCos(alpha, beta) >= 0) {
            return Dist(Line(beam.a_, beam.b_), v);
        } else {
            return Dist(beam.a_, v);
        }
    }

    long double Dist(Beam &&beam, Vector &&v) {
        Vector alpha = beam.b_ - beam.a_;
        Vector beta = v - beam.a_;
        if (AngleCos(alpha, beta) >= 0) {
            return Dist(Line(beam.a_, beam.b_), v);
        } else {
            return Dist(beam.a_, v);
        }
    }

    long double Dist(const Segment &segment, const Vector &v) {
        Vector alpha1 = segment.b_ - segment.a_;
        Vector beta1 = v - segment.a_;
        Vector alpha2 = segment.a_ - segment.b_;
        Vector beta2 = v - segment.b_;
        if (AngleCos(alpha1, beta1) >= 0 && AngleCos(alpha2, beta2) >= 0) {
            return Dist(Line(segment.a_, segment.b_), v);
        } else {
            return std::min(Dist(segment.a_, v), Dist(segment.b_, v));
        }
    }

    long double Dist(const Segment &segment, Vector &&v) {
        Vector alpha1 = segment.b_ - segment.a_;
        Vector beta1 = v - segment.a_;
        Vector alpha2 = segment.a_ - segment.b_;
        Vector beta2 = v - segment.b_;
        if (AngleCos(alpha1, beta1) >= 0 && AngleCos(alpha2, beta2) >= 0) {
            return Dist(Line(segment.a_, segment.b_), v);
        } else {
            return std::min(Dist(segment.a_, v), Dist(segment.b_, v));
        }
    }

    long double Dist(Segment &&segment, const Vector &v) {
        Vector alpha1 = segment.b_ - segment.a_;
        Vector beta1 = v - segment.a_;
        Vector alpha2 = segment.a_ - segment.b_;
        Vector beta2 = v - segment.b_;
        if (AngleCos(alpha1, beta1) >= 0 && AngleCos(alpha2, beta2) >= 0) {
            return Dist(Line(segment.a_, segment.b_), v);
        } else {
            return std::min(Dist(segment.a_, v), Dist(segment.b_, v));
        }
    }

    long double Dist(Segment &&segment, Vector &&v) {
        Vector alpha1 = segment.b_ - segment.a_;
        Vector beta1 = v - segment.a_;
        Vector alpha2 = segment.a_ - segment.b_;
        Vector beta2 = v - segment.b_;
        if (AngleCos(alpha1, beta1) >= 0 && AngleCos(alpha2, beta2) >= 0) {
            return Dist(Line(segment.a_, segment.b_), v);
        } else {
            return std::min(Dist(segment.a_, v), Dist(segment.b_, v));
        }
    }

    bool OnSameSideEq(const Line &line, const Vector &a, const Vector &b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return true;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSideEq(const Line &line, const Vector &a, Vector &&b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return true;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSideEq(const Line &line, Vector &&a, Vector &&b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return true;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSideEq(Line &&line, const Vector &a, const Vector &b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return true;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSideEq(Line &&line, const Vector &a, Vector &&b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return true;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSideEq(Line &&line, Vector &&a, Vector &&b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return true;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSide(const Line &line, const Vector &a, const Vector &b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return false;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSide(const Line &line, const Vector &a, Vector &&b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return false;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSide(const Line &line, Vector &&a, Vector &&b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return false;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSide(Line &&line, const Vector &a, const Vector &b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return false;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSide(Line &&line, const Vector &a, Vector &&b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return false;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool OnSameSide(Line &&line, Vector &&a, Vector &&b) {
        long double alpha1 = line.A_ * a.x_ + line.B_ * a.y_ + line.C_;
        long double alpha2 = line.A_ * b.x_ + line.B_ * b.y_ + line.C_;

        if (std::fabs(alpha1) < kEps || std::fabs(alpha2) < kEps) {
            return false;
        } else {
            if ((alpha1 < 0 && alpha2 < 0) || (alpha1 > 0 && alpha2 > 0)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool Intersect(const Segment &s1, const Segment &s2) {
        if (s1.a_ == s2.a_ || s1.a_ == s2.b_ || s1.b_ == s2.a_ || s1.b_ == s2.b_) {
            return true;
        } else if (s1.a_ == s1.b_) {
            return LiesOn(s2, s1.a_);
        } else if (s2.a_ == s2.b_) {
            return LiesOn(s1, s2.a_);
        }
        if (Line(s1.a_, s1.b_) == Line(s2.a_, s2.b_)) { // проверяем, что хотя бы одна точка s2 лежит на отрезке s1
            if (LiesOn(s1, s2.a_) || LiesOn(s1, s2.b_)) {
                return true;
            } else {
                return false;
            }
        }
        if (OnSameSide(Line(s1.a_, s1.b_), s2.a_, s2.b_) || OnSameSide(Line(s2.a_, s2.b_), s1.a_, s1.b_)) {
            return false;
        } else {
            return true;
        }
    }

    bool Intersect(const Segment &s1, Segment &&s2) {
        if (s1.a_ == s2.a_ || s1.a_ == s2.b_ || s1.b_ == s2.a_ || s1.b_ == s2.b_) {
            return true;
        } else if (s1.a_ == s1.b_) {
            return LiesOn(s2, s1.a_);
        } else if (s2.a_ == s2.b_) {
            return LiesOn(s1, s2.a_);
        }
        if (Line(s1.a_, s1.b_) == Line(s2.a_, s2.b_)) { // проверяем, что хотя бы одна точка s2 лежит на отрезке s1
            if (LiesOn(s1, s2.a_) || LiesOn(s1, s2.b_)) {
                return true;
            } else {
                return false;
            }
        }
        if (OnSameSide(Line(s1.a_, s1.b_), s2.a_, s2.b_) || OnSameSide(Line(s2.a_, s2.b_), s1.a_, s1.b_)) {
            return false;
        } else {
            return true;
        }
    }

    bool Intersect(Segment &&s1, Segment &&s2) {
        if (s1.a_ == s2.a_ || s1.a_ == s2.b_ || s1.b_ == s2.a_ || s1.b_ == s2.b_) {
            return true;
        } else if (s1.a_ == s1.b_) {
            return LiesOn(s2, s1.a_);
        } else if (s2.a_ == s2.b_) {
            return LiesOn(s1, s2.a_);
        }
        if (Line(s1.a_, s1.b_) == Line(s2.a_, s2.b_)) { // проверяем, что хотя бы одна точка s2 лежит на отрезке s1
            if (LiesOn(s1, s2.a_) || LiesOn(s1, s2.b_)) {
                return true;
            } else {
                return false;
            }
        }
        if (OnSameSide(Line(s1.a_, s1.b_), s2.a_, s2.b_) || OnSameSide(Line(s2.a_, s2.b_), s1.a_, s1.b_)) {
            return false;
        } else {
            return true;
        }
    }

    bool IsBetween(const Vector &a, const Vector &b, const Vector &m) {
        long double bm = VectorMultiplication(b, m);
        long double ma = VectorMultiplication(m, a);
        if ((bm >= -kEps && ma >= -kEps) || (bm <= kEps && ma <= kEps)) { // !!!!!!!!!!!!
            return true;
        } else {
            return false;
        }
    }

    bool IsBetween(const Vector &a, const Vector &b, Vector &&m) {
        long double bm = VectorMultiplication(b, m);
        long double ma = VectorMultiplication(m, a);
        if ((bm >= -kEps && ma >= -kEps) || (bm <= kEps && ma <= kEps)) { // !!!!!!!!!!!!
            return true;
        } else {
            return false;
        }
    }

    bool IsBetween(const Vector &a, Vector &&b, const Vector &m) {
        long double bm = VectorMultiplication(b, m);
        long double ma = VectorMultiplication(m, a);
        if ((bm >= -kEps && ma >= -kEps) || (bm <= kEps && ma <= kEps)) { // !!!!!!!!!!!!
            return true;
        } else {
            return false;
        }
    }

    bool IsBetween(const Vector &a, Vector &&b, Vector &&m) {
        long double bm = VectorMultiplication(b, m);
        long double ma = VectorMultiplication(m, a);
        if ((bm >= -kEps && ma >= -kEps) || (bm <= kEps && ma <= kEps)) { // !!!!!!!!!!!!
            return true;
        } else {
            return false;
        }
    }

    bool IsBetween(Vector &&a, const Vector &b, const Vector &m) {
        long double bm = VectorMultiplication(b, m);
        long double ma = VectorMultiplication(m, a);
        if ((bm >= -kEps && ma >= -kEps) || (bm <= kEps && ma <= kEps)) { // !!!!!!!!!!!!
            return true;
        } else {
            return false;
        }
    }

    bool IsBetween(Vector &&a, const Vector &b, Vector &&m) {
        long double bm = VectorMultiplication(b, m);
        long double ma = VectorMultiplication(m, a);
        if ((bm >= -kEps && ma >= -kEps) || (bm <= kEps && ma <= kEps)) { // !!!!!!!!!!!!
            return true;
        } else {
            return false;
        }
    }

    bool IsBetween(Vector &&a, Vector &&b, const Vector &m) {
        long double bm = VectorMultiplication(b, m);
        long double ma = VectorMultiplication(m, a);
        if ((bm >= -kEps && ma >= -kEps) || (bm <= kEps && ma <= kEps)) { // !!!!!!!!!!!!
            return true;
        } else {
            return false;
        }
    }

    bool IsBetween(Vector &&a, Vector &&b, Vector &&m) {
        long double bm = VectorMultiplication(b, m);
        long double ma = VectorMultiplication(m, a);
        if ((bm >= -kEps && ma >= -kEps) || (bm <= kEps && ma <= kEps)) { // !!!!!!!!!!!!
            return true;
        } else {
            return false;
        }
    }
}
