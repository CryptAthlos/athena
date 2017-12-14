// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "CryptAthlosCore/Account.h"
#include "CryptAthlosCore/CryptAthlosFormatUtils.h"
#include "CryptAthlosCore/Currency.h"

class TransactionBuilder {
public:

  typedef std::vector<CryptAthlos::AccountKeys> KeysVector;
  typedef std::vector<Crypto::Signature> SignatureVector;
  typedef std::vector<SignatureVector> SignatureMultivector;

  struct MultisignatureSource {
    CryptAthlos::MultisignatureInput input;
    KeysVector keys;
    Crypto::PublicKey srcTxPubKey;
    size_t srcOutputIndex;
  };

  TransactionBuilder(const CryptAthlos::Currency& currency, uint64_t unlockTime = 0);

  // regenerate transaction keys
  TransactionBuilder& newTxKeys();
  TransactionBuilder& setTxKeys(const CryptAthlos::KeyPair& txKeys);

  // inputs
  TransactionBuilder& setInput(const std::vector<CryptAthlos::TransactionSourceEntry>& sources, const CryptAthlos::AccountKeys& senderKeys);
  TransactionBuilder& addMultisignatureInput(const MultisignatureSource& source);

  // outputs
  TransactionBuilder& setOutput(const std::vector<CryptAthlos::TransactionDestinationEntry>& destinations);
  TransactionBuilder& addOutput(const CryptAthlos::TransactionDestinationEntry& dest);
  TransactionBuilder& addMultisignatureOut(uint64_t amount, const KeysVector& keys, uint32_t required);

  CryptAthlos::Transaction build() const;

  std::vector<CryptAthlos::TransactionSourceEntry> m_sources;
  std::vector<CryptAthlos::TransactionDestinationEntry> m_destinations;

private:

  void fillInputs(CryptAthlos::Transaction& tx, std::vector<CryptAthlos::KeyPair>& contexts) const;
  void fillOutputs(CryptAthlos::Transaction& tx) const;
  void signSources(const Crypto::Hash& prefixHash, const std::vector<CryptAthlos::KeyPair>& contexts, CryptAthlos::Transaction& tx) const;

  struct MultisignatureDestination {
    uint64_t amount;
    uint32_t requiredSignatures;
    KeysVector keys;
  };

  CryptAthlos::AccountKeys m_senderKeys;

  std::vector<MultisignatureSource> m_msigSources;
  std::vector<MultisignatureDestination> m_msigDestinations;

  size_t m_version;
  uint64_t m_unlockTime;
  CryptAthlos::KeyPair m_txKey;
  const CryptAthlos::Currency& m_currency;
};
