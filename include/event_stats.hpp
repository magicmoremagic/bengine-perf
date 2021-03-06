#pragma once
#ifndef BE_PERF_EVENT_STATS_HPP_
#define BE_PERF_EVENT_STATS_HPP_

#include "event_stat.hpp"
#include <be/core/pair_value_iterators.hpp>
#include <unordered_map>

namespace be::perf {

///////////////////////////////////////////////////////////////////////////////
class EventStats final : Immovable {
   friend class Stats;
   using map = std::unordered_map<Id, EventStat>;
public:
   using iterator = PairSecondIterator<map::iterator>;
   using const_iterator = PairSecondIterator<map::const_iterator>;

   iterator begin()              { return iterator(map_.begin()); }
   const_iterator begin() const  { return const_iterator(map_.begin()); }
   iterator end()                { return iterator(map_.end()); }
   const_iterator end() const    { return const_iterator(map_.end()); }

   size_t size() const { return map_.size(); }
   bool empty() const  { return map_.empty(); }

   EventStat& operator[](Id id);
   EventStat& operator[](const S& name);

   void clear();

private:
   EventStats(Stats& stats);

   Stats& stats_;
   map map_;
};

} // be::perf

#endif
