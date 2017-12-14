// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <vector>
#include <unordered_map>

#include "CryptAthlosCore/Account.h"
#include "CryptAthlosCore/CryptAthlosBasic.h"
#include "CryptAthlosCore/Currency.h"
#include "CryptAthlosCore/BlockchainIndices.h"
#include "crypto/hash.h"

#include "../TestGenerator/TestGenerator.h"

class TestBlockchainGenerator
{
public:
  TestBlockchainGenerator(const CryptAthlos::Currency& currency);

  //TODO: get rid of this method
  std::vector<CryptAthlos::Block>& getBlockchain();
  std::vector<CryptAthlos::Block> getBlockchainCopy();
  void generateEmptyBlocks(size_t count);
  bool getBlockRewardForAddress(const CryptAthlos::AccountPublicAddress& address);
  bool generateTransactionsInOneBlock(const CryptAthlos::AccountPublicAddress& address, size_t n);
  bool getSingleOutputTransaction(const CryptAthlos::AccountPublicAddress& address, uint64_t amount);
  void addTxToBlockchain(const CryptAthlos::Transaction& transaction);
  bool getTransactionByHash(const Crypto::Hash& hash, CryptAthlos::Transaction& tx, bool checkTxPool = false);
  const CryptAthlos::AccountBase& getMinerAccount() const;
  bool generateFromBaseTx(const CryptAthlos::AccountBase& address);

  void putTxToPool(const CryptAthlos::Transaction& tx);
  void getPoolSymmetricDifference(std::vector<Crypto::Hash>&& known_pool_tx_ids, Crypto::Hash known_block_id, bool& is_bc_actual,
    std::vector<CryptAthlos::Transaction>& new_txs, std::vector<Crypto::Hash>& deleted_tx_ids);
  void putTxPoolToBlockchain();
  void clearTxPool();

  void cutBlockchain(uint32_t height);

  bool addOrphan(const Crypto::Hash& hash, uint32_t height);
  bool getGeneratedTransactionsNumber(uint32_t height, uint64_t& generatedTransactions);
  bool getOrphanBlockIdsByHeight(uint32_t height, std::vector<Crypto::Hash>& blockHashes);
  bool getBlockIdsByTimestamp(uint64_t timestampBegin, uint64_t timestampEnd, uint32_t blocksNumberLimit, std::vector<Crypto::Hash>& hashes, uint32_t& blocksNumberWithinTimestamps);
  bool getPoolTransactionIdsByTimestamp(uint64_t timestampBegin, uint64_t timestampEnd, uint32_t transactionsNumberLimit, std::vector<Crypto::Hash>& hashes, uint64_t& transactionsNumberWithinTimestamps);
  bool getTransactionIdsByPaymentId(const Crypto::Hash& paymentId, std::vector<Crypto::Hash>& transactionHashes);

  bool getTransactionGlobalIndexesByHash(const Crypto::Hash& transactionHash, std::vector<uint32_t>& globalIndexes);
  bool getMultisignatureOutputByGlobalIndex(uint64_t amount, uint32_t globalIndex, CryptAthlos::MultisignatureOutput& out);
  void setMinerAccount(const CryptAthlos::AccountBase& account);

private:
  struct MultisignatureOutEntry {
    Crypto::Hash transactionHash;
    uint16_t indexOut;
  };

  struct KeyOutEntry {
    Crypto::Hash transactionHash;
    uint16_t indexOut;
  };
  
  void addGenesisBlock();
  void addMiningBlock();

  const CryptAthlos::Currency& m_currency;
  test_generator generator;
  CryptAthlos::AccountBase miner_acc;
  std::vector<CryptAthlos::Block> m_blockchain;
  std::unordered_map<Crypto::Hash, CryptAthlos::Transaction> m_txs;
  std::unordered_map<Crypto::Hash, std::vector<uint32_t>> transactionGlobalOuts;
  std::unordered_map<uint64_t, std::vector<MultisignatureOutEntry>> multisignatureOutsIndex;
  std::unordered_map<uint64_t, std::vector<KeyOutEntry>> keyOutsIndex;

  std::unordered_map<Crypto::Hash, CryptAthlos::Transaction> m_txPool;
  mutable std::mutex m_mutex;

  CryptAthlos::PaymentIdIndex m_paymentIdIndex;
  CryptAthlos::TimestampTransactionsIndex m_timestampIndex;
  CryptAthlos::GeneratedTransactionsIndex m_generatedTransactionsIndex;
  CryptAthlos::OrphanBlocksIndex m_orthanBlocksIndex;

  void addToBlockchain(const CryptAthlos::Transaction& tx);
  void addToBlockchain(const std::vector<CryptAthlos::Transaction>& txs);
  void addToBlockchain(const std::vector<CryptAthlos::Transaction>& txs, const CryptAthlos::AccountBase& minerAddress);
  void addTx(const CryptAthlos::Transaction& tx);

  bool doGenerateTransactionsInOneBlock(CryptAthlos::AccountPublicAddress const &address, size_t n);
};
