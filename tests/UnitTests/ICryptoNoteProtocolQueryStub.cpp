// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ICryptAthlosProtocolQueryStub.h"

bool ICryptAthlosProtocolQueryStub::addObserver(CryptAthlos::ICryptAthlosProtocolObserver* observer) {
  return false;
}

bool ICryptAthlosProtocolQueryStub::removeObserver(CryptAthlos::ICryptAthlosProtocolObserver* observer) {
  return false;
}

uint32_t ICryptAthlosProtocolQueryStub::getObservedHeight() const {
  return observedHeight;
}

size_t ICryptAthlosProtocolQueryStub::getPeerCount() const {
  return peers;
}

bool ICryptAthlosProtocolQueryStub::isSynchronized() const {
  return synchronized;
}

void ICryptAthlosProtocolQueryStub::setPeerCount(uint32_t count) {
  peers = count;
}

void ICryptAthlosProtocolQueryStub::setObservedHeight(uint32_t height) {
  observedHeight = height;
}

void ICryptAthlosProtocolQueryStub::setSynchronizedStatus(bool status) {
    synchronized = status;
}
