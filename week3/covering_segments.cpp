#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool segmentComparator(Segment s1, Segment s2){
  return s1.start < s2.start;  
}

vector<int> optimal_points(vector<Segment> &segments) {
  std::sort(segments.begin(), segments.end(), segmentComparator);
  vector<int> points;
  
  Segment segment;
  segment.start = segments[0].start;
  segment.end = segments[0].end;
    
  for (size_t i = 1; i < segments.size(); ++i) {
    if(segments[i].start > segment.end){
      points.push_back(segment.end);
      segment.start = segments[i].start;
      segment.end = segments[i].end;
    } else{
      if(segments[i].end < segment.end){
        segment.end = segments[i].end;
      }
    }    
  }
  points.push_back(segment.end);
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
