// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once 
#include "Chaingen.h"

/************************************************************************/
/*                                                                      */
/************************************************************************/
class gen_simple_chain_split_1 : public test_chain_unit_base 
{
public: 
  gen_simple_chain_split_1();
  bool generate(std::vector<test_event_entry> &events) const; 
  bool check_split_not_switched(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_split_not_switched2(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_split_switched(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_split_not_switched_back(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_split_switched_back_1(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_split_switched_back_2(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_mempool_1(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_mempool_2(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  /*bool check_orphaned_chain_1(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_orphaned_switched_to_alternative(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_orphaned_chain_2(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_orphaned_switched_to_main(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_orphaned_chain_38(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_orphaned_chain_39(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_orphaned_chain_40(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
  bool check_orphaned_chain_41(CryptAthlos::core& c, size_t ev_index, const std::vector<test_event_entry> &events); */
private:
};
