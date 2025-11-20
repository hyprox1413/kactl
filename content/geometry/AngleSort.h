/**
 * Author: Mark Wen
 * Date: 2024-11-11
 * License: Unknown
 * Source: https://codeforces.com/blog/entry/72815
 * Description: Sorts points radially across the origin.
 * To sort around a point, sort a-p and b-p.
 * Status: tested on https://codeforces.com/gym/104901/problem/M
 */

#pragma once

#include "Point.h"

template<class P>
void anglesort(vector<pair<P, ll>> &v, P p=P(0, 0)) {
	sort(all(v), [p](pair<P, ll> pa, pair<P, ll> pb) {
	  P a = pa.first - p, b = pb.first - p;
		return a.half() == b.half() ? a.cross(b) > 0 : a.half() < b.half();
	});
}
 
template<class P>
bool angleBetween(const P& a, const P& b, const P& c, const P& p=P(0, 0)) {
  vector<pair<P, ll>> v = {{a, 0}, {b, 1}, {c, 2}};
  anglesort(v, p);
  rotate(v.begin(), find(all(v), pair<P, ll> {a, 0}), v.end());
  return v[1] == pair<P, ll> {b, 1};
}
