/* Copyright (C) 2018 Hai Liang Wang<hailiang.hl.wang@gmail.com> - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GPL 3.0 license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the GPL 3.0 license with
 * this file. If not, visit: https://www.gnu.org/licenses/gpl-howto.en.html
 */
#pragma once

#include <nan.h>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <fstream>
#include <sys/stat.h>

using namespace std;
using namespace v8;
typedef std::map<std::string, std::vector<float> > WordVectorMap;

namespace synonyms {
namespace word2vec {
class Reader : public Nan::ObjectWrap {
 private:  // functions
  void clear();
  void updateNormVectors();

 protected:  // variables
  WordVectorMap* word_vectors;
  WordVectorMap* word_vectors_norm;
  long long num_dims;
  long long num_words;

 public:  // variables
 public:  // functions
  explicit Reader();
  ~Reader();

  //
  static void Init(v8::Local<v8::Object> exports);
  static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static Nan::Persistent<v8::Function> constructor;
  // end

  /**
   * 程序定义的接口
   * @param info [description]
   */
  static void Initialize(
      const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void GetVector(
      const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void FindClosestWords(
      const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void GetEmbeddingDim(
      const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void GetVocabSize(
      const Nan::FunctionCallbackInfo<v8::Value>& info);
};
}  // word2vec
}  // synonyms