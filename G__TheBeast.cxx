// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__TheBeast

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "TheBeast.h"
#include "TheRatPack.h"
#include "TheSampleFile.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *HistDefinition_Dictionary();
   static void HistDefinition_TClassManip(TClass*);
   static void *new_HistDefinition(void *p = 0);
   static void *newArray_HistDefinition(Long_t size, void *p);
   static void delete_HistDefinition(void *p);
   static void deleteArray_HistDefinition(void *p);
   static void destruct_HistDefinition(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HistDefinition*)
   {
      ::HistDefinition *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HistDefinition));
      static ::ROOT::TGenericClassInfo 
         instance("HistDefinition", "TheRatPack.h", 8,
                  typeid(::HistDefinition), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HistDefinition_Dictionary, isa_proxy, 4,
                  sizeof(::HistDefinition) );
      instance.SetNew(&new_HistDefinition);
      instance.SetNewArray(&newArray_HistDefinition);
      instance.SetDelete(&delete_HistDefinition);
      instance.SetDeleteArray(&deleteArray_HistDefinition);
      instance.SetDestructor(&destruct_HistDefinition);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HistDefinition*)
   {
      return GenerateInitInstanceLocal((::HistDefinition*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HistDefinition*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HistDefinition_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HistDefinition*)0x0)->GetClass();
      HistDefinition_TClassManip(theClass);
   return theClass;
   }

   static void HistDefinition_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("file_name","TheRatPack.h");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TheRatPack_Dictionary();
   static void TheRatPack_TClassManip(TClass*);
   static void *new_TheRatPack(void *p = 0);
   static void *newArray_TheRatPack(Long_t size, void *p);
   static void delete_TheRatPack(void *p);
   static void deleteArray_TheRatPack(void *p);
   static void destruct_TheRatPack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TheRatPack*)
   {
      ::TheRatPack *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TheRatPack));
      static ::ROOT::TGenericClassInfo 
         instance("TheRatPack", "TheRatPack.h", 17,
                  typeid(::TheRatPack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TheRatPack_Dictionary, isa_proxy, 4,
                  sizeof(::TheRatPack) );
      instance.SetNew(&new_TheRatPack);
      instance.SetNewArray(&newArray_TheRatPack);
      instance.SetDelete(&delete_TheRatPack);
      instance.SetDeleteArray(&deleteArray_TheRatPack);
      instance.SetDestructor(&destruct_TheRatPack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TheRatPack*)
   {
      return GenerateInitInstanceLocal((::TheRatPack*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TheRatPack*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TheRatPack_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TheRatPack*)0x0)->GetClass();
      TheRatPack_TClassManip(theClass);
   return theClass;
   }

   static void TheRatPack_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("file_name","TheRatPack.h");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TheBeast_Dictionary();
   static void TheBeast_TClassManip(TClass*);
   static void delete_TheBeast(void *p);
   static void deleteArray_TheBeast(void *p);
   static void destruct_TheBeast(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TheBeast*)
   {
      ::TheBeast *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TheBeast));
      static ::ROOT::TGenericClassInfo 
         instance("TheBeast", "TheBeast.h", 9,
                  typeid(::TheBeast), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TheBeast_Dictionary, isa_proxy, 4,
                  sizeof(::TheBeast) );
      instance.SetDelete(&delete_TheBeast);
      instance.SetDeleteArray(&deleteArray_TheBeast);
      instance.SetDestructor(&destruct_TheBeast);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TheBeast*)
   {
      return GenerateInitInstanceLocal((::TheBeast*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TheBeast*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TheBeast_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TheBeast*)0x0)->GetClass();
      TheBeast_TClassManip(theClass);
   return theClass;
   }

   static void TheBeast_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("file_name","TheBeast.h");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TheSampleFile_Dictionary();
   static void TheSampleFile_TClassManip(TClass*);
   static void delete_TheSampleFile(void *p);
   static void deleteArray_TheSampleFile(void *p);
   static void destruct_TheSampleFile(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TheSampleFile*)
   {
      ::TheSampleFile *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TheSampleFile));
      static ::ROOT::TGenericClassInfo 
         instance("TheSampleFile", "TheSampleFile.h", 8,
                  typeid(::TheSampleFile), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TheSampleFile_Dictionary, isa_proxy, 4,
                  sizeof(::TheSampleFile) );
      instance.SetDelete(&delete_TheSampleFile);
      instance.SetDeleteArray(&deleteArray_TheSampleFile);
      instance.SetDestructor(&destruct_TheSampleFile);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TheSampleFile*)
   {
      return GenerateInitInstanceLocal((::TheSampleFile*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TheSampleFile*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TheSampleFile_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TheSampleFile*)0x0)->GetClass();
      TheSampleFile_TClassManip(theClass);
   return theClass;
   }

   static void TheSampleFile_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("file_name","TheSampleFile.h");
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_HistDefinition(void *p) {
      return  p ? new(p) ::HistDefinition : new ::HistDefinition;
   }
   static void *newArray_HistDefinition(Long_t nElements, void *p) {
      return p ? new(p) ::HistDefinition[nElements] : new ::HistDefinition[nElements];
   }
   // Wrapper around operator delete
   static void delete_HistDefinition(void *p) {
      delete ((::HistDefinition*)p);
   }
   static void deleteArray_HistDefinition(void *p) {
      delete [] ((::HistDefinition*)p);
   }
   static void destruct_HistDefinition(void *p) {
      typedef ::HistDefinition current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HistDefinition

namespace ROOT {
   // Wrappers around operator new
   static void *new_TheRatPack(void *p) {
      return  p ? new(p) ::TheRatPack : new ::TheRatPack;
   }
   static void *newArray_TheRatPack(Long_t nElements, void *p) {
      return p ? new(p) ::TheRatPack[nElements] : new ::TheRatPack[nElements];
   }
   // Wrapper around operator delete
   static void delete_TheRatPack(void *p) {
      delete ((::TheRatPack*)p);
   }
   static void deleteArray_TheRatPack(void *p) {
      delete [] ((::TheRatPack*)p);
   }
   static void destruct_TheRatPack(void *p) {
      typedef ::TheRatPack current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TheRatPack

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TheBeast(void *p) {
      delete ((::TheBeast*)p);
   }
   static void deleteArray_TheBeast(void *p) {
      delete [] ((::TheBeast*)p);
   }
   static void destruct_TheBeast(void *p) {
      typedef ::TheBeast current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TheBeast

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TheSampleFile(void *p) {
      delete ((::TheSampleFile*)p);
   }
   static void deleteArray_TheSampleFile(void *p) {
      delete [] ((::TheSampleFile*)p);
   }
   static void destruct_TheSampleFile(void *p) {
      typedef ::TheSampleFile current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TheSampleFile

namespace ROOT {
   static TClass *maplEstringcOTheSamplemUgR_Dictionary();
   static void maplEstringcOTheSamplemUgR_TClassManip(TClass*);
   static void *new_maplEstringcOTheSamplemUgR(void *p = 0);
   static void *newArray_maplEstringcOTheSamplemUgR(Long_t size, void *p);
   static void delete_maplEstringcOTheSamplemUgR(void *p);
   static void deleteArray_maplEstringcOTheSamplemUgR(void *p);
   static void destruct_maplEstringcOTheSamplemUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,TheSample*>*)
   {
      map<string,TheSample*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,TheSample*>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,TheSample*>", -2, "map", 96,
                  typeid(map<string,TheSample*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOTheSamplemUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,TheSample*>) );
      instance.SetNew(&new_maplEstringcOTheSamplemUgR);
      instance.SetNewArray(&newArray_maplEstringcOTheSamplemUgR);
      instance.SetDelete(&delete_maplEstringcOTheSamplemUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOTheSamplemUgR);
      instance.SetDestructor(&destruct_maplEstringcOTheSamplemUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,TheSample*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,TheSample*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOTheSamplemUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,TheSample*>*)0x0)->GetClass();
      maplEstringcOTheSamplemUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOTheSamplemUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOTheSamplemUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,TheSample*> : new map<string,TheSample*>;
   }
   static void *newArray_maplEstringcOTheSamplemUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,TheSample*>[nElements] : new map<string,TheSample*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOTheSamplemUgR(void *p) {
      delete ((map<string,TheSample*>*)p);
   }
   static void deleteArray_maplEstringcOTheSamplemUgR(void *p) {
      delete [] ((map<string,TheSample*>*)p);
   }
   static void destruct_maplEstringcOTheSamplemUgR(void *p) {
      typedef map<string,TheSample*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,TheSample*>

namespace ROOT {
   static TClass *maplEstringcOHistDefinitiongR_Dictionary();
   static void maplEstringcOHistDefinitiongR_TClassManip(TClass*);
   static void *new_maplEstringcOHistDefinitiongR(void *p = 0);
   static void *newArray_maplEstringcOHistDefinitiongR(Long_t size, void *p);
   static void delete_maplEstringcOHistDefinitiongR(void *p);
   static void deleteArray_maplEstringcOHistDefinitiongR(void *p);
   static void destruct_maplEstringcOHistDefinitiongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,HistDefinition>*)
   {
      map<string,HistDefinition> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,HistDefinition>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,HistDefinition>", -2, "map", 96,
                  typeid(map<string,HistDefinition>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOHistDefinitiongR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,HistDefinition>) );
      instance.SetNew(&new_maplEstringcOHistDefinitiongR);
      instance.SetNewArray(&newArray_maplEstringcOHistDefinitiongR);
      instance.SetDelete(&delete_maplEstringcOHistDefinitiongR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOHistDefinitiongR);
      instance.SetDestructor(&destruct_maplEstringcOHistDefinitiongR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,HistDefinition> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,HistDefinition>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOHistDefinitiongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,HistDefinition>*)0x0)->GetClass();
      maplEstringcOHistDefinitiongR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOHistDefinitiongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOHistDefinitiongR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,HistDefinition> : new map<string,HistDefinition>;
   }
   static void *newArray_maplEstringcOHistDefinitiongR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,HistDefinition>[nElements] : new map<string,HistDefinition>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOHistDefinitiongR(void *p) {
      delete ((map<string,HistDefinition>*)p);
   }
   static void deleteArray_maplEstringcOHistDefinitiongR(void *p) {
      delete [] ((map<string,HistDefinition>*)p);
   }
   static void destruct_maplEstringcOHistDefinitiongR(void *p) {
      typedef map<string,HistDefinition> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,HistDefinition>

namespace {
  void TriggerDictionaryInitialization_libTheBeast_Impl() {
    static const char* headers[] = {
"TheBeast.h",
"TheRatPack.h",
"TheSampleFile.h",
0
    };
    static const char* includePaths[] = {
"/home/kkrizka/Sources/root/builddir/include",
"/home/kkrizka/Sources/root/builddir/include",
"/home/kkrizka/Code/jupyroot/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libTheBeast dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
struct __attribute__((annotate(R"ATTRDUMP(file_name@@@TheRatPack.h)ATTRDUMP"))) __attribute__((annotate(R"ATTRDUMP(pattern@@@*)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TheRatPack.h")))  __attribute__((annotate("$clingAutoload$TheBeast.h")))  HistDefinition;
class __attribute__((annotate(R"ATTRDUMP(file_name@@@TheRatPack.h)ATTRDUMP"))) __attribute__((annotate(R"ATTRDUMP(pattern@@@*)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TheRatPack.h")))  __attribute__((annotate("$clingAutoload$TheBeast.h")))  TheRatPack;
class __attribute__((annotate(R"ATTRDUMP(file_name@@@TheBeast.h)ATTRDUMP"))) __attribute__((annotate(R"ATTRDUMP(pattern@@@*)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TheBeast.h")))  TheBeast;
class __attribute__((annotate(R"ATTRDUMP(file_name@@@TheSampleFile.h)ATTRDUMP"))) __attribute__((annotate(R"ATTRDUMP(pattern@@@*)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$TheSampleFile.h")))  TheSampleFile;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libTheBeast dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "TheBeast.h"
#include "TheRatPack.h"
#include "TheSampleFile.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"", payloadCode, "@",
"HistDefinition", payloadCode, "@",
"TheBeast", payloadCode, "@",
"TheBeast::m_beast", payloadCode, "@",
"TheRatPack", payloadCode, "@",
"TheSampleFile", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libTheBeast",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libTheBeast_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libTheBeast_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libTheBeast() {
  TriggerDictionaryInitialization_libTheBeast_Impl();
}
