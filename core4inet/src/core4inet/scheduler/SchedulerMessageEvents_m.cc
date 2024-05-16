//
// Generated file, do not edit! Created by nedtool 5.5 from core4inet/scheduler/SchedulerMessageEvents.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "SchedulerMessageEvents_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace CoRE4INET {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(SchedulerActionTimeEvent)

SchedulerActionTimeEvent::SchedulerActionTimeEvent(const char *name, short kind) : ::CoRE4INET::SchedulerEvent(name,kind)
{
    this->action_time = 0;
    this->next_cycle = false;
}

SchedulerActionTimeEvent::SchedulerActionTimeEvent(const SchedulerActionTimeEvent& other) : ::CoRE4INET::SchedulerEvent(other)
{
    copy(other);
}

SchedulerActionTimeEvent::~SchedulerActionTimeEvent()
{
}

SchedulerActionTimeEvent& SchedulerActionTimeEvent::operator=(const SchedulerActionTimeEvent& other)
{
    if (this==&other) return *this;
    ::CoRE4INET::SchedulerEvent::operator=(other);
    copy(other);
    return *this;
}

void SchedulerActionTimeEvent::copy(const SchedulerActionTimeEvent& other)
{
    this->action_time = other.action_time;
    this->next_cycle = other.next_cycle;
}

void SchedulerActionTimeEvent::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::CoRE4INET::SchedulerEvent::parsimPack(b);
    doParsimPacking(b,this->action_time);
    doParsimPacking(b,this->next_cycle);
}

void SchedulerActionTimeEvent::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::CoRE4INET::SchedulerEvent::parsimUnpack(b);
    doParsimUnpacking(b,this->action_time);
    doParsimUnpacking(b,this->next_cycle);
}

uint32_t SchedulerActionTimeEvent::getAction_time() const
{
    return this->action_time;
}

void SchedulerActionTimeEvent::setAction_time(uint32_t action_time)
{
    this->action_time = action_time;
}

bool SchedulerActionTimeEvent::getNext_cycle() const
{
    return this->next_cycle;
}

void SchedulerActionTimeEvent::setNext_cycle(bool next_cycle)
{
    this->next_cycle = next_cycle;
}

class SchedulerActionTimeEventDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SchedulerActionTimeEventDescriptor();
    virtual ~SchedulerActionTimeEventDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(SchedulerActionTimeEventDescriptor)

SchedulerActionTimeEventDescriptor::SchedulerActionTimeEventDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::SchedulerActionTimeEvent", "CoRE4INET::SchedulerEvent")
{
    propertynames = nullptr;
}

SchedulerActionTimeEventDescriptor::~SchedulerActionTimeEventDescriptor()
{
    delete[] propertynames;
}

bool SchedulerActionTimeEventDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SchedulerActionTimeEvent *>(obj)!=nullptr;
}

const char **SchedulerActionTimeEventDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SchedulerActionTimeEventDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SchedulerActionTimeEventDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SchedulerActionTimeEventDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *SchedulerActionTimeEventDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "action_time",
        "next_cycle",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SchedulerActionTimeEventDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "action_time")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "next_cycle")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SchedulerActionTimeEventDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",
        "bool",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SchedulerActionTimeEventDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SchedulerActionTimeEventDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SchedulerActionTimeEventDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SchedulerActionTimeEvent *pp = (SchedulerActionTimeEvent *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SchedulerActionTimeEventDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SchedulerActionTimeEvent *pp = (SchedulerActionTimeEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SchedulerActionTimeEventDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SchedulerActionTimeEvent *pp = (SchedulerActionTimeEvent *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getAction_time());
        case 1: return bool2string(pp->getNext_cycle());
        default: return "";
    }
}

bool SchedulerActionTimeEventDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SchedulerActionTimeEvent *pp = (SchedulerActionTimeEvent *)object; (void)pp;
    switch (field) {
        case 0: pp->setAction_time(string2ulong(value)); return true;
        case 1: pp->setNext_cycle(string2bool(value)); return true;
        default: return false;
    }
}

const char *SchedulerActionTimeEventDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *SchedulerActionTimeEventDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SchedulerActionTimeEvent *pp = (SchedulerActionTimeEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SchedulerTimerEvent)

SchedulerTimerEvent::SchedulerTimerEvent(const char *name, short kind) : ::CoRE4INET::SchedulerEvent(name,kind)
{
    this->timer = 0;
}

SchedulerTimerEvent::SchedulerTimerEvent(const SchedulerTimerEvent& other) : ::CoRE4INET::SchedulerEvent(other)
{
    copy(other);
}

SchedulerTimerEvent::~SchedulerTimerEvent()
{
}

SchedulerTimerEvent& SchedulerTimerEvent::operator=(const SchedulerTimerEvent& other)
{
    if (this==&other) return *this;
    ::CoRE4INET::SchedulerEvent::operator=(other);
    copy(other);
    return *this;
}

void SchedulerTimerEvent::copy(const SchedulerTimerEvent& other)
{
    this->timer = other.timer;
}

void SchedulerTimerEvent::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::CoRE4INET::SchedulerEvent::parsimPack(b);
    doParsimPacking(b,this->timer);
}

void SchedulerTimerEvent::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::CoRE4INET::SchedulerEvent::parsimUnpack(b);
    doParsimUnpacking(b,this->timer);
}

uint64_t SchedulerTimerEvent::getTimer() const
{
    return this->timer;
}

void SchedulerTimerEvent::setTimer(uint64_t timer)
{
    this->timer = timer;
}

class SchedulerTimerEventDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SchedulerTimerEventDescriptor();
    virtual ~SchedulerTimerEventDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(SchedulerTimerEventDescriptor)

SchedulerTimerEventDescriptor::SchedulerTimerEventDescriptor() : omnetpp::cClassDescriptor("CoRE4INET::SchedulerTimerEvent", "CoRE4INET::SchedulerEvent")
{
    propertynames = nullptr;
}

SchedulerTimerEventDescriptor::~SchedulerTimerEventDescriptor()
{
    delete[] propertynames;
}

bool SchedulerTimerEventDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SchedulerTimerEvent *>(obj)!=nullptr;
}

const char **SchedulerTimerEventDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SchedulerTimerEventDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SchedulerTimerEventDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SchedulerTimerEventDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *SchedulerTimerEventDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "timer",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SchedulerTimerEventDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timer")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SchedulerTimerEventDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SchedulerTimerEventDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *SchedulerTimerEventDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int SchedulerTimerEventDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SchedulerTimerEvent *pp = (SchedulerTimerEvent *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SchedulerTimerEventDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SchedulerTimerEvent *pp = (SchedulerTimerEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SchedulerTimerEventDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SchedulerTimerEvent *pp = (SchedulerTimerEvent *)object; (void)pp;
    switch (field) {
        case 0: return uint642string(pp->getTimer());
        default: return "";
    }
}

bool SchedulerTimerEventDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SchedulerTimerEvent *pp = (SchedulerTimerEvent *)object; (void)pp;
    switch (field) {
        case 0: pp->setTimer(string2uint64(value)); return true;
        default: return false;
    }
}

const char *SchedulerTimerEventDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *SchedulerTimerEventDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SchedulerTimerEvent *pp = (SchedulerTimerEvent *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace CoRE4INET

