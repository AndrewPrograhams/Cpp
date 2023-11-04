#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

enum class Traffic_Light { Green, Yellow, Red};
Traffic_Light& operator++(Traffic_Light& t);
Traffic_Light& operator--(Traffic_Light& t);
bool operator==(Traffic_Light t, Traffic_Light u);
#endif

