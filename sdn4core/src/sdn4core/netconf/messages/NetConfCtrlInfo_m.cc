//
// Generated file, do not edit! Created by nedtool 5.5 from sdn4core/netconf/messages/NetConfCtrlInfo.msg.
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
#include "NetConfCtrlInfo_m.h"

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

namespace SDN4CoRE {

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

Register_Class(NetConfCtrlInfo)

NetConfCtrlInfo::NetConfCtrlInfo() : ::omnetpp::cObject()
{
    this->messageType = 0;
    this->session_id = 0;
}

NetConfCtrlInfo::NetConfCtrlInfo(const NetConfCtrlInfo& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

NetConfCtrlInfo::~NetConfCtrlInfo()
{
}

NetConfCtrlInfo& NetConfCtrlInfo::operator=(const NetConfCtrlInfo& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void NetConfCtrlInfo::copy(const NetConfCtrlInfo& other)
{
    this->messageType = other.messageType;
    this->message_id = other.message_id;
    this->session_id = other.session_id;
}

void NetConfCtrlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->messageType);
    doParsimPacking(b,this->message_id);
    doParsimPacking(b,this->session_id);
}

void NetConfCtrlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->messageType);
    doParsimUnpacking(b,this->message_id);
    doParsimUnpacking(b,this->session_id);
}

int NetConfCtrlInfo::getMessageType() const
{
    return this->messageType;
}

void NetConfCtrlInfo::setMessageType(int messageType)
{
    this->messageType = messageType;
}

const char * NetConfCtrlInfo::getMessage_id() const
{
    return this->message_id.c_str();
}

void NetConfCtrlInfo::setMessage_id(const char * message_id)
{
    this->message_id = message_id;
}

int NetConfCtrlInfo::getSession_id() const
{
    return this->session_id;
}

void NetConfCtrlInfo::setSession_id(int session_id)
{
    this->session_id = session_id;
}

class NetConfCtrlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfCtrlInfoDescriptor();
    virtual ~NetConfCtrlInfoDescriptor();

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

Register_ClassDescriptor(NetConfCtrlInfoDescriptor)

NetConfCtrlInfoDescriptor::NetConfCtrlInfoDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfCtrlInfo", "omnetpp::cObject")
{
    propertynames = nullptr;
}

NetConfCtrlInfoDescriptor::~NetConfCtrlInfoDescriptor()
{
    delete[] propertynames;
}

bool NetConfCtrlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfCtrlInfo *>(obj)!=nullptr;
}

const char **NetConfCtrlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfCtrlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfCtrlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int NetConfCtrlInfoDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *NetConfCtrlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageType",
        "message_id",
        "session_id",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int NetConfCtrlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageType")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "message_id")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "session_id")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfCtrlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfCtrlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *NetConfCtrlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "SDN4CoRE::NetConfMessageType";
            return nullptr;
        default: return nullptr;
    }
}

int NetConfCtrlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfCtrlInfo *pp = (NetConfCtrlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfCtrlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfCtrlInfo *pp = (NetConfCtrlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfCtrlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfCtrlInfo *pp = (NetConfCtrlInfo *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getMessageType(), "SDN4CoRE::NetConfMessageType");
        case 1: return oppstring2string(pp->getMessage_id());
        case 2: return long2string(pp->getSession_id());
        default: return "";
    }
}

bool NetConfCtrlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfCtrlInfo *pp = (NetConfCtrlInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageType((SDN4CoRE::NetConfMessageType)string2enum(value, "SDN4CoRE::NetConfMessageType")); return true;
        case 1: pp->setMessage_id((value)); return true;
        case 2: pp->setSession_id(string2long(value)); return true;
        default: return false;
    }
}

const char *NetConfCtrlInfoDescriptor::getFieldStructName(int field) const
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

void *NetConfCtrlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfCtrlInfo *pp = (NetConfCtrlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfClientCtrlInfo_Connection)

NetConfClientCtrlInfo_Connection::NetConfClientCtrlInfo_Connection() : ::omnetpp::cObject()
{
    this->localPort = 0;
    this->connectPort = 0;
}

NetConfClientCtrlInfo_Connection::NetConfClientCtrlInfo_Connection(const NetConfClientCtrlInfo_Connection& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

NetConfClientCtrlInfo_Connection::~NetConfClientCtrlInfo_Connection()
{
}

NetConfClientCtrlInfo_Connection& NetConfClientCtrlInfo_Connection::operator=(const NetConfClientCtrlInfo_Connection& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void NetConfClientCtrlInfo_Connection::copy(const NetConfClientCtrlInfo_Connection& other)
{
    this->localPort = other.localPort;
    this->connectAddress = other.connectAddress;
    this->connectPort = other.connectPort;
}

void NetConfClientCtrlInfo_Connection::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->connectAddress);
    doParsimPacking(b,this->connectPort);
}

void NetConfClientCtrlInfo_Connection::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->connectAddress);
    doParsimUnpacking(b,this->connectPort);
}

int NetConfClientCtrlInfo_Connection::getLocalPort() const
{
    return this->localPort;
}

void NetConfClientCtrlInfo_Connection::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

const char * NetConfClientCtrlInfo_Connection::getConnectAddress() const
{
    return this->connectAddress.c_str();
}

void NetConfClientCtrlInfo_Connection::setConnectAddress(const char * connectAddress)
{
    this->connectAddress = connectAddress;
}

int NetConfClientCtrlInfo_Connection::getConnectPort() const
{
    return this->connectPort;
}

void NetConfClientCtrlInfo_Connection::setConnectPort(int connectPort)
{
    this->connectPort = connectPort;
}

class NetConfClientCtrlInfo_ConnectionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfClientCtrlInfo_ConnectionDescriptor();
    virtual ~NetConfClientCtrlInfo_ConnectionDescriptor();

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

Register_ClassDescriptor(NetConfClientCtrlInfo_ConnectionDescriptor)

NetConfClientCtrlInfo_ConnectionDescriptor::NetConfClientCtrlInfo_ConnectionDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfClientCtrlInfo_Connection", "omnetpp::cObject")
{
    propertynames = nullptr;
}

NetConfClientCtrlInfo_ConnectionDescriptor::~NetConfClientCtrlInfo_ConnectionDescriptor()
{
    delete[] propertynames;
}

bool NetConfClientCtrlInfo_ConnectionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfClientCtrlInfo_Connection *>(obj)!=nullptr;
}

const char **NetConfClientCtrlInfo_ConnectionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfClientCtrlInfo_ConnectionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfClientCtrlInfo_ConnectionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int NetConfClientCtrlInfo_ConnectionDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *NetConfClientCtrlInfo_ConnectionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localPort",
        "connectAddress",
        "connectPort",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int NetConfClientCtrlInfo_ConnectionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localPort")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "connectAddress")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "connectPort")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfClientCtrlInfo_ConnectionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfClientCtrlInfo_ConnectionDescriptor::getFieldPropertyNames(int field) const
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

const char *NetConfClientCtrlInfo_ConnectionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NetConfClientCtrlInfo_ConnectionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfClientCtrlInfo_Connection *pp = (NetConfClientCtrlInfo_Connection *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfClientCtrlInfo_ConnectionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfClientCtrlInfo_Connection *pp = (NetConfClientCtrlInfo_Connection *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfClientCtrlInfo_ConnectionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfClientCtrlInfo_Connection *pp = (NetConfClientCtrlInfo_Connection *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getLocalPort());
        case 1: return oppstring2string(pp->getConnectAddress());
        case 2: return long2string(pp->getConnectPort());
        default: return "";
    }
}

bool NetConfClientCtrlInfo_ConnectionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfClientCtrlInfo_Connection *pp = (NetConfClientCtrlInfo_Connection *)object; (void)pp;
    switch (field) {
        case 0: pp->setLocalPort(string2long(value)); return true;
        case 1: pp->setConnectAddress((value)); return true;
        case 2: pp->setConnectPort(string2long(value)); return true;
        default: return false;
    }
}

const char *NetConfClientCtrlInfo_ConnectionDescriptor::getFieldStructName(int field) const
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

void *NetConfClientCtrlInfo_ConnectionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfClientCtrlInfo_Connection *pp = (NetConfClientCtrlInfo_Connection *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace SDN4CoRE

