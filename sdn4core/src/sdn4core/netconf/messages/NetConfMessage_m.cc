//
// Generated file, do not edit! Created by nedtool 5.5 from sdn4core/netconf/messages/NetConfMessage.msg.
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
#include "NetConfMessage_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("SDN4CoRE::NetConfMessageType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("SDN4CoRE::NetConfMessageType"));
    e->insert(NETCONFMESSAGETYPE_RPC, "NETCONFMESSAGETYPE_RPC");
    e->insert(NETCONFMESSAGETYPE_RPCREPLY, "NETCONFMESSAGETYPE_RPCREPLY");
)

Register_Class(NetConfMessage)

NetConfMessage::NetConfMessage(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->messageType = 0;
}

NetConfMessage::NetConfMessage(const NetConfMessage& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

NetConfMessage::~NetConfMessage()
{
}

NetConfMessage& NetConfMessage::operator=(const NetConfMessage& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void NetConfMessage::copy(const NetConfMessage& other)
{
    this->messageType = other.messageType;
}

void NetConfMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->messageType);
}

void NetConfMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->messageType);
}

int NetConfMessage::getMessageType() const
{
    return this->messageType;
}

void NetConfMessage::setMessageType(int messageType)
{
    this->messageType = messageType;
}

class NetConfMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfMessageDescriptor();
    virtual ~NetConfMessageDescriptor();

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

Register_ClassDescriptor(NetConfMessageDescriptor)

NetConfMessageDescriptor::NetConfMessageDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfMessage", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

NetConfMessageDescriptor::~NetConfMessageDescriptor()
{
    delete[] propertynames;
}

bool NetConfMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfMessage *>(obj)!=nullptr;
}

const char **NetConfMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NetConfMessageDescriptor::getFieldTypeFlags(int field) const
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

const char *NetConfMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int NetConfMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageType")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *NetConfMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NetConfMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage *pp = (NetConfMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage *pp = (NetConfMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage *pp = (NetConfMessage *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getMessageType(), "SDN4CoRE::NetConfMessageType");
        default: return "";
    }
}

bool NetConfMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage *pp = (NetConfMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageType((SDN4CoRE::NetConfMessageType)string2enum(value, "SDN4CoRE::NetConfMessageType")); return true;
        default: return false;
    }
}

const char *NetConfMessageDescriptor::getFieldStructName(int field) const
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

void *NetConfMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage *pp = (NetConfMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfMessage_RPC)

NetConfMessage_RPC::NetConfMessage_RPC(const char *name, short kind) : ::SDN4CoRE::NetConfMessage(name,kind)
{
    this->setMessageType(NetConfMessageType::NETCONFMESSAGETYPE_RPC);
    this->setByteLength(25);

}

NetConfMessage_RPC::NetConfMessage_RPC(const NetConfMessage_RPC& other) : ::SDN4CoRE::NetConfMessage(other)
{
    copy(other);
}

NetConfMessage_RPC::~NetConfMessage_RPC()
{
}

NetConfMessage_RPC& NetConfMessage_RPC::operator=(const NetConfMessage_RPC& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfMessage::operator=(other);
    copy(other);
    return *this;
}

void NetConfMessage_RPC::copy(const NetConfMessage_RPC& other)
{
    this->message_id = other.message_id;
}

void NetConfMessage_RPC::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfMessage::parsimPack(b);
    doParsimPacking(b,this->message_id);
}

void NetConfMessage_RPC::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->message_id);
}

const char * NetConfMessage_RPC::getMessage_id() const
{
    return this->message_id.c_str();
}

void NetConfMessage_RPC::setMessage_id(const char * message_id)
{
    this->message_id = message_id;
}

class NetConfMessage_RPCDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfMessage_RPCDescriptor();
    virtual ~NetConfMessage_RPCDescriptor();

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

Register_ClassDescriptor(NetConfMessage_RPCDescriptor)

NetConfMessage_RPCDescriptor::NetConfMessage_RPCDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfMessage_RPC", "SDN4CoRE::NetConfMessage")
{
    propertynames = nullptr;
}

NetConfMessage_RPCDescriptor::~NetConfMessage_RPCDescriptor()
{
    delete[] propertynames;
}

bool NetConfMessage_RPCDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfMessage_RPC *>(obj)!=nullptr;
}

const char **NetConfMessage_RPCDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfMessage_RPCDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfMessage_RPCDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NetConfMessage_RPCDescriptor::getFieldTypeFlags(int field) const
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

const char *NetConfMessage_RPCDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "message_id",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int NetConfMessage_RPCDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "message_id")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfMessage_RPCDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfMessage_RPCDescriptor::getFieldPropertyNames(int field) const
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

const char *NetConfMessage_RPCDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NetConfMessage_RPCDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPC *pp = (NetConfMessage_RPC *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfMessage_RPCDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPC *pp = (NetConfMessage_RPC *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfMessage_RPCDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPC *pp = (NetConfMessage_RPC *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getMessage_id());
        default: return "";
    }
}

bool NetConfMessage_RPCDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPC *pp = (NetConfMessage_RPC *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessage_id((value)); return true;
        default: return false;
    }
}

const char *NetConfMessage_RPCDescriptor::getFieldStructName(int field) const
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

void *NetConfMessage_RPCDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPC *pp = (NetConfMessage_RPC *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConf_RPCReplyElement)

NetConf_RPCReplyElement::NetConf_RPCReplyElement(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
}

NetConf_RPCReplyElement::NetConf_RPCReplyElement(const NetConf_RPCReplyElement& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

NetConf_RPCReplyElement::~NetConf_RPCReplyElement()
{
}

NetConf_RPCReplyElement& NetConf_RPCReplyElement::operator=(const NetConf_RPCReplyElement& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void NetConf_RPCReplyElement::copy(const NetConf_RPCReplyElement& other)
{
}

void NetConf_RPCReplyElement::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
}

void NetConf_RPCReplyElement::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
}

class NetConf_RPCReplyElementDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConf_RPCReplyElementDescriptor();
    virtual ~NetConf_RPCReplyElementDescriptor();

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

Register_ClassDescriptor(NetConf_RPCReplyElementDescriptor)

NetConf_RPCReplyElementDescriptor::NetConf_RPCReplyElementDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConf_RPCReplyElement", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

NetConf_RPCReplyElementDescriptor::~NetConf_RPCReplyElementDescriptor()
{
    delete[] propertynames;
}

bool NetConf_RPCReplyElementDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConf_RPCReplyElement *>(obj)!=nullptr;
}

const char **NetConf_RPCReplyElementDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConf_RPCReplyElementDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConf_RPCReplyElementDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int NetConf_RPCReplyElementDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *NetConf_RPCReplyElementDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int NetConf_RPCReplyElementDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConf_RPCReplyElementDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **NetConf_RPCReplyElementDescriptor::getFieldPropertyNames(int field) const
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

const char *NetConf_RPCReplyElementDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NetConf_RPCReplyElementDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement *pp = (NetConf_RPCReplyElement *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConf_RPCReplyElementDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement *pp = (NetConf_RPCReplyElement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConf_RPCReplyElementDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement *pp = (NetConf_RPCReplyElement *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool NetConf_RPCReplyElementDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement *pp = (NetConf_RPCReplyElement *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetConf_RPCReplyElementDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *NetConf_RPCReplyElementDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement *pp = (NetConf_RPCReplyElement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConfMessage_RPCReply)

NetConfMessage_RPCReply::NetConfMessage_RPCReply(const char *name, short kind) : ::SDN4CoRE::NetConfMessage(name,kind)
{
    this->setMessageType(NetConfMessageType::NETCONFMESSAGETYPE_RPCREPLY);
    this->setByteLength(37);

}

NetConfMessage_RPCReply::NetConfMessage_RPCReply(const NetConfMessage_RPCReply& other) : ::SDN4CoRE::NetConfMessage(other)
{
    copy(other);
}

NetConfMessage_RPCReply::~NetConfMessage_RPCReply()
{
}

NetConfMessage_RPCReply& NetConfMessage_RPCReply::operator=(const NetConfMessage_RPCReply& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConfMessage::operator=(other);
    copy(other);
    return *this;
}

void NetConfMessage_RPCReply::copy(const NetConfMessage_RPCReply& other)
{
    this->message_id = other.message_id;
}

void NetConfMessage_RPCReply::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConfMessage::parsimPack(b);
    doParsimPacking(b,this->message_id);
}

void NetConfMessage_RPCReply::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConfMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->message_id);
}

const char * NetConfMessage_RPCReply::getMessage_id() const
{
    return this->message_id.c_str();
}

void NetConfMessage_RPCReply::setMessage_id(const char * message_id)
{
    this->message_id = message_id;
}

class NetConfMessage_RPCReplyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConfMessage_RPCReplyDescriptor();
    virtual ~NetConfMessage_RPCReplyDescriptor();

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

Register_ClassDescriptor(NetConfMessage_RPCReplyDescriptor)

NetConfMessage_RPCReplyDescriptor::NetConfMessage_RPCReplyDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConfMessage_RPCReply", "SDN4CoRE::NetConfMessage")
{
    propertynames = nullptr;
}

NetConfMessage_RPCReplyDescriptor::~NetConfMessage_RPCReplyDescriptor()
{
    delete[] propertynames;
}

bool NetConfMessage_RPCReplyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConfMessage_RPCReply *>(obj)!=nullptr;
}

const char **NetConfMessage_RPCReplyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConfMessage_RPCReplyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConfMessage_RPCReplyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int NetConfMessage_RPCReplyDescriptor::getFieldTypeFlags(int field) const
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

const char *NetConfMessage_RPCReplyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "message_id",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int NetConfMessage_RPCReplyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "message_id")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConfMessage_RPCReplyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConfMessage_RPCReplyDescriptor::getFieldPropertyNames(int field) const
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

const char *NetConfMessage_RPCReplyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NetConfMessage_RPCReplyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPCReply *pp = (NetConfMessage_RPCReply *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConfMessage_RPCReplyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPCReply *pp = (NetConfMessage_RPCReply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConfMessage_RPCReplyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPCReply *pp = (NetConfMessage_RPCReply *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getMessage_id());
        default: return "";
    }
}

bool NetConfMessage_RPCReplyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPCReply *pp = (NetConfMessage_RPCReply *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessage_id((value)); return true;
        default: return false;
    }
}

const char *NetConfMessage_RPCReplyDescriptor::getFieldStructName(int field) const
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

void *NetConfMessage_RPCReplyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConfMessage_RPCReply *pp = (NetConfMessage_RPCReply *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConf_RPCReplyElement_Data)

NetConf_RPCReplyElement_Data::NetConf_RPCReplyElement_Data(const char *name, short kind) : ::SDN4CoRE::NetConf_RPCReplyElement(name,kind)
{
}

NetConf_RPCReplyElement_Data::NetConf_RPCReplyElement_Data(const NetConf_RPCReplyElement_Data& other) : ::SDN4CoRE::NetConf_RPCReplyElement(other)
{
    copy(other);
}

NetConf_RPCReplyElement_Data::~NetConf_RPCReplyElement_Data()
{
}

NetConf_RPCReplyElement_Data& NetConf_RPCReplyElement_Data::operator=(const NetConf_RPCReplyElement_Data& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConf_RPCReplyElement::operator=(other);
    copy(other);
    return *this;
}

void NetConf_RPCReplyElement_Data::copy(const NetConf_RPCReplyElement_Data& other)
{
}

void NetConf_RPCReplyElement_Data::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConf_RPCReplyElement::parsimPack(b);
}

void NetConf_RPCReplyElement_Data::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConf_RPCReplyElement::parsimUnpack(b);
}

class NetConf_RPCReplyElement_DataDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConf_RPCReplyElement_DataDescriptor();
    virtual ~NetConf_RPCReplyElement_DataDescriptor();

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

Register_ClassDescriptor(NetConf_RPCReplyElement_DataDescriptor)

NetConf_RPCReplyElement_DataDescriptor::NetConf_RPCReplyElement_DataDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConf_RPCReplyElement_Data", "SDN4CoRE::NetConf_RPCReplyElement")
{
    propertynames = nullptr;
}

NetConf_RPCReplyElement_DataDescriptor::~NetConf_RPCReplyElement_DataDescriptor()
{
    delete[] propertynames;
}

bool NetConf_RPCReplyElement_DataDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConf_RPCReplyElement_Data *>(obj)!=nullptr;
}

const char **NetConf_RPCReplyElement_DataDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConf_RPCReplyElement_DataDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConf_RPCReplyElement_DataDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int NetConf_RPCReplyElement_DataDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *NetConf_RPCReplyElement_DataDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int NetConf_RPCReplyElement_DataDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConf_RPCReplyElement_DataDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **NetConf_RPCReplyElement_DataDescriptor::getFieldPropertyNames(int field) const
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

const char *NetConf_RPCReplyElement_DataDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NetConf_RPCReplyElement_DataDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Data *pp = (NetConf_RPCReplyElement_Data *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConf_RPCReplyElement_DataDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Data *pp = (NetConf_RPCReplyElement_Data *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConf_RPCReplyElement_DataDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Data *pp = (NetConf_RPCReplyElement_Data *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool NetConf_RPCReplyElement_DataDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Data *pp = (NetConf_RPCReplyElement_Data *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetConf_RPCReplyElement_DataDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *NetConf_RPCReplyElement_DataDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Data *pp = (NetConf_RPCReplyElement_Data *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("SDN4CoRE::NetConf_RPCReplyElement_Error_Type");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("SDN4CoRE::NetConf_RPCReplyElement_Error_Type"));
    e->insert(NETCONF_REPLY_ERROR_TYPE_TRANSPORT, "NETCONF_REPLY_ERROR_TYPE_TRANSPORT");
    e->insert(NETCONF_REPLY_ERROR_TYPE_RPC, "NETCONF_REPLY_ERROR_TYPE_RPC");
    e->insert(NETCONF_REPLY_ERROR_TYPE_PROTOCOL, "NETCONF_REPLY_ERROR_TYPE_PROTOCOL");
    e->insert(NETCONF_REPLY_ERROR_TYPE_APPLICATION, "NETCONF_REPLY_ERROR_TYPE_APPLICATION");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("SDN4CoRE::NetConf_RPCReplyElement_Error_Severity");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("SDN4CoRE::NetConf_RPCReplyElement_Error_Severity"));
    e->insert(NETCONF_REPLY_ERROR_SEVIRITY_ERROR, "NETCONF_REPLY_ERROR_SEVIRITY_ERROR");
    e->insert(NETCONF_REPLY_ERROR_SEVIRITY_WARNING, "NETCONF_REPLY_ERROR_SEVIRITY_WARNING");
)

Register_Class(NetConf_RPCReplyElement_Error)

NetConf_RPCReplyElement_Error::NetConf_RPCReplyElement_Error(const char *name, short kind) : ::SDN4CoRE::NetConf_RPCReplyElement(name,kind)
{
    this->setByteLength(131);

    this->error_type = 0;
    this->error_severity = 0;
}

NetConf_RPCReplyElement_Error::NetConf_RPCReplyElement_Error(const NetConf_RPCReplyElement_Error& other) : ::SDN4CoRE::NetConf_RPCReplyElement(other)
{
    copy(other);
}

NetConf_RPCReplyElement_Error::~NetConf_RPCReplyElement_Error()
{
}

NetConf_RPCReplyElement_Error& NetConf_RPCReplyElement_Error::operator=(const NetConf_RPCReplyElement_Error& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConf_RPCReplyElement::operator=(other);
    copy(other);
    return *this;
}

void NetConf_RPCReplyElement_Error::copy(const NetConf_RPCReplyElement_Error& other)
{
    this->error_type = other.error_type;
    this->error_tag = other.error_tag;
    this->error_severity = other.error_severity;
    this->error_app_tag = other.error_app_tag;
}

void NetConf_RPCReplyElement_Error::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConf_RPCReplyElement::parsimPack(b);
    doParsimPacking(b,this->error_type);
    doParsimPacking(b,this->error_tag);
    doParsimPacking(b,this->error_severity);
    doParsimPacking(b,this->error_app_tag);
}

void NetConf_RPCReplyElement_Error::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConf_RPCReplyElement::parsimUnpack(b);
    doParsimUnpacking(b,this->error_type);
    doParsimUnpacking(b,this->error_tag);
    doParsimUnpacking(b,this->error_severity);
    doParsimUnpacking(b,this->error_app_tag);
}

int NetConf_RPCReplyElement_Error::getError_type() const
{
    return this->error_type;
}

void NetConf_RPCReplyElement_Error::setError_type(int error_type)
{
    this->error_type = error_type;
}

const char * NetConf_RPCReplyElement_Error::getError_tag() const
{
    return this->error_tag.c_str();
}

void NetConf_RPCReplyElement_Error::setError_tag(const char * error_tag)
{
    this->error_tag = error_tag;
}

int NetConf_RPCReplyElement_Error::getError_severity() const
{
    return this->error_severity;
}

void NetConf_RPCReplyElement_Error::setError_severity(int error_severity)
{
    this->error_severity = error_severity;
}

const char * NetConf_RPCReplyElement_Error::getError_app_tag() const
{
    return this->error_app_tag.c_str();
}

void NetConf_RPCReplyElement_Error::setError_app_tag(const char * error_app_tag)
{
    this->error_app_tag = error_app_tag;
}

class NetConf_RPCReplyElement_ErrorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConf_RPCReplyElement_ErrorDescriptor();
    virtual ~NetConf_RPCReplyElement_ErrorDescriptor();

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

Register_ClassDescriptor(NetConf_RPCReplyElement_ErrorDescriptor)

NetConf_RPCReplyElement_ErrorDescriptor::NetConf_RPCReplyElement_ErrorDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConf_RPCReplyElement_Error", "SDN4CoRE::NetConf_RPCReplyElement")
{
    propertynames = nullptr;
}

NetConf_RPCReplyElement_ErrorDescriptor::~NetConf_RPCReplyElement_ErrorDescriptor()
{
    delete[] propertynames;
}

bool NetConf_RPCReplyElement_ErrorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConf_RPCReplyElement_Error *>(obj)!=nullptr;
}

const char **NetConf_RPCReplyElement_ErrorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConf_RPCReplyElement_ErrorDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConf_RPCReplyElement_ErrorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int NetConf_RPCReplyElement_ErrorDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *NetConf_RPCReplyElement_ErrorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "error_type",
        "error_tag",
        "error_severity",
        "error_app_tag",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int NetConf_RPCReplyElement_ErrorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "error_type")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "error_tag")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "error_severity")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "error_app_tag")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConf_RPCReplyElement_ErrorDescriptor::getFieldTypeString(int field) const
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
        "string",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **NetConf_RPCReplyElement_ErrorDescriptor::getFieldPropertyNames(int field) const
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
        case 2: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *NetConf_RPCReplyElement_ErrorDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "SDN4CoRE::NetConf_RPCReplyElement_Error_Type";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"enum")) return "SDN4CoRE::NetConf_RPCReplyElement_Error_Severity";
            return nullptr;
        default: return nullptr;
    }
}

int NetConf_RPCReplyElement_ErrorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Error *pp = (NetConf_RPCReplyElement_Error *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConf_RPCReplyElement_ErrorDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Error *pp = (NetConf_RPCReplyElement_Error *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConf_RPCReplyElement_ErrorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Error *pp = (NetConf_RPCReplyElement_Error *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getError_type(), "SDN4CoRE::NetConf_RPCReplyElement_Error_Type");
        case 1: return oppstring2string(pp->getError_tag());
        case 2: return enum2string(pp->getError_severity(), "SDN4CoRE::NetConf_RPCReplyElement_Error_Severity");
        case 3: return oppstring2string(pp->getError_app_tag());
        default: return "";
    }
}

bool NetConf_RPCReplyElement_ErrorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Error *pp = (NetConf_RPCReplyElement_Error *)object; (void)pp;
    switch (field) {
        case 0: pp->setError_type((SDN4CoRE::NetConf_RPCReplyElement_Error_Type)string2enum(value, "SDN4CoRE::NetConf_RPCReplyElement_Error_Type")); return true;
        case 1: pp->setError_tag((value)); return true;
        case 2: pp->setError_severity((SDN4CoRE::NetConf_RPCReplyElement_Error_Severity)string2enum(value, "SDN4CoRE::NetConf_RPCReplyElement_Error_Severity")); return true;
        case 3: pp->setError_app_tag((value)); return true;
        default: return false;
    }
}

const char *NetConf_RPCReplyElement_ErrorDescriptor::getFieldStructName(int field) const
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

void *NetConf_RPCReplyElement_ErrorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Error *pp = (NetConf_RPCReplyElement_Error *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NetConf_RPCReplyElement_Ok)

NetConf_RPCReplyElement_Ok::NetConf_RPCReplyElement_Ok(const char *name, short kind) : ::SDN4CoRE::NetConf_RPCReplyElement(name,kind)
{
    this->setByteLength(5);
}

NetConf_RPCReplyElement_Ok::NetConf_RPCReplyElement_Ok(const NetConf_RPCReplyElement_Ok& other) : ::SDN4CoRE::NetConf_RPCReplyElement(other)
{
    copy(other);
}

NetConf_RPCReplyElement_Ok::~NetConf_RPCReplyElement_Ok()
{
}

NetConf_RPCReplyElement_Ok& NetConf_RPCReplyElement_Ok::operator=(const NetConf_RPCReplyElement_Ok& other)
{
    if (this==&other) return *this;
    ::SDN4CoRE::NetConf_RPCReplyElement::operator=(other);
    copy(other);
    return *this;
}

void NetConf_RPCReplyElement_Ok::copy(const NetConf_RPCReplyElement_Ok& other)
{
}

void NetConf_RPCReplyElement_Ok::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::SDN4CoRE::NetConf_RPCReplyElement::parsimPack(b);
}

void NetConf_RPCReplyElement_Ok::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::SDN4CoRE::NetConf_RPCReplyElement::parsimUnpack(b);
}

class NetConf_RPCReplyElement_OkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NetConf_RPCReplyElement_OkDescriptor();
    virtual ~NetConf_RPCReplyElement_OkDescriptor();

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

Register_ClassDescriptor(NetConf_RPCReplyElement_OkDescriptor)

NetConf_RPCReplyElement_OkDescriptor::NetConf_RPCReplyElement_OkDescriptor() : omnetpp::cClassDescriptor("SDN4CoRE::NetConf_RPCReplyElement_Ok", "SDN4CoRE::NetConf_RPCReplyElement")
{
    propertynames = nullptr;
}

NetConf_RPCReplyElement_OkDescriptor::~NetConf_RPCReplyElement_OkDescriptor()
{
    delete[] propertynames;
}

bool NetConf_RPCReplyElement_OkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NetConf_RPCReplyElement_Ok *>(obj)!=nullptr;
}

const char **NetConf_RPCReplyElement_OkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NetConf_RPCReplyElement_OkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NetConf_RPCReplyElement_OkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int NetConf_RPCReplyElement_OkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *NetConf_RPCReplyElement_OkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int NetConf_RPCReplyElement_OkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NetConf_RPCReplyElement_OkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **NetConf_RPCReplyElement_OkDescriptor::getFieldPropertyNames(int field) const
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

const char *NetConf_RPCReplyElement_OkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NetConf_RPCReplyElement_OkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Ok *pp = (NetConf_RPCReplyElement_Ok *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NetConf_RPCReplyElement_OkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Ok *pp = (NetConf_RPCReplyElement_Ok *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NetConf_RPCReplyElement_OkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Ok *pp = (NetConf_RPCReplyElement_Ok *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool NetConf_RPCReplyElement_OkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Ok *pp = (NetConf_RPCReplyElement_Ok *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NetConf_RPCReplyElement_OkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *NetConf_RPCReplyElement_OkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NetConf_RPCReplyElement_Ok *pp = (NetConf_RPCReplyElement_Ok *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace SDN4CoRE

