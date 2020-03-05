// https://en.wikipedia.org/wiki/Graham_scan
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

struct Point {
  float x;
  float y;
};

Point g_min_point;

float CrossProduct(Point first, Point second, Point curr) {
  return (second.x - first.x) * (curr.y - second.y) -
         (second.y - first.y) * (curr.x - first.x);
}

bool ComparePointByAngle(const Point& lhs, const Point& rhs) {
  float cross_product = CrossProduct(g_min_point, lhs, rhs);
  if (cross_product == 0) return lhs.x < rhs.x;
  return cross_product > 0;
}

int main() {
  std::default_random_engine generator;
  std::uniform_real_distribution<float> dist(-1.0, 1.0);
  const int kNumPoints = 5;

  std::vector<Point> points;
  points.reserve(kNumPoints);

  g_min_point.x = std::numeric_limits<float>::max();
  g_min_point.y = std::numeric_limits<float>::max();
  for (int i = 0; i < kNumPoints; ++i) {
    Point point;
    point.x = dist(generator);
    point.y = dist(generator);
    points.push_back(point);
    if (point.y < g_min_point.y) {
      g_min_point.y = point.y;
      g_min_point.x = point.x;
    }
  }

  sort(points.begin(), points.end(), ComparePointByAngle);

  for (int i = 0; i < kNumPoints; ++i) {
    std::cout << points[i].y << points[i].x << std::endl;
  }
}