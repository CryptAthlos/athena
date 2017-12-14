// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <future>
#include <map>
#include <mutex>

#include "crypto/hash.h"
#include "IWalletLegacy.h"

namespace CryptAthlos {
namespace WalletHelper {

class SaveWalletResultObserver : public CryptAthlos::IWalletLegacyObserver {
public:
  std::promise<std::error_code> saveResult;
  virtual void saveCompleted(std::error_code result) override { saveResult.set_value(result); }
};

class InitWalletResultObserver : public CryptAthlos::IWalletLegacyObserver {
public:
  std::promise<std::error_code> initResult;
  virtual void initCompleted(std::error_code result) override { initResult.set_value(result); }
};

class SendCompleteResultObserver : public CryptAthlos::IWalletLegacyObserver {
public:
  virtual void sendTransactionCompleted(CryptAthlos::TransactionId transactionId, std::error_code result) override;
  std::error_code wait(CryptAthlos::TransactionId transactionId);

private:
  std::mutex m_mutex;
  std::condition_variable m_condition;
  std::map<CryptAthlos::TransactionId, std::error_code> m_finishedTransactions;
  std::error_code m_result;
};

class IWalletRemoveObserverGuard {
public:
  IWalletRemoveObserverGuard(CryptAthlos::IWalletLegacy& wallet, CryptAthlos::IWalletLegacyObserver& observer);
  ~IWalletRemoveObserverGuard();

  void removeObserver();

private:
  CryptAthlos::IWalletLegacy& m_wallet;
  CryptAthlos::IWalletLegacyObserver& m_observer;
  bool m_removed;
};

void prepareFileNames(const std::string& file_path, std::string& keys_file, std::string& wallet_file);
void storeWallet(CryptAthlos::IWalletLegacy& wallet, const std::string& walletFilename);

}
}
