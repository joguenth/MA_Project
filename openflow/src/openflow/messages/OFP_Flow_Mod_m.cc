//
// Generated file, do not edit! Created by nedtool 5.5 from openflow/messages/OFP_Flow_Mod.msg.
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
#include "OFP_Flow_Mod_m.h"

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

namespace openflow {

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

Register_Class(OFP_Flow_Mod)

OFP_Flow_Mod::OFP_Flow_Mod(const char *name, short kind) : ::openflow::Open_Flow_Message(name,kind)
{
    this->cookie = 0;
    this->cookie_mask = 0;
    this->table_id = 0;
    this->command = 0;
    this->idle_timeout = 0;
    this->hard_timeout = 0;
    this->priority = 0;
    this->buffer_id = 0;
    this->out_port = 0;
    this->out_group = 0;
    this->flags = 0;
    for (unsigned int i=0; i<2; i++)
        this->pad[i] = 0;
    actions_arraysize = 0;
    this->actions = 0;
}

OFP_Flow_Mod::OFP_Flow_Mod(const OFP_Flow_Mod& other) : ::openflow::Open_Flow_Message(other)
{
    actions_arraysize = 0;
    this->actions = 0;
    copy(other);
}

OFP_Flow_Mod::~OFP_Flow_Mod()
{
    delete [] this->actions;
}

OFP_Flow_Mod& OFP_Flow_Mod::operator=(const OFP_Flow_Mod& other)
{
    if (this==&other) return *this;
    ::openflow::Open_Flow_Message::operator=(other);
    copy(other);
    return *this;
}

void OFP_Flow_Mod::copy(const OFP_Flow_Mod& other)
{
    this->cookie = other.cookie;
    this->cookie_mask = other.cookie_mask;
    this->table_id = other.table_id;
    this->command = other.command;
    this->idle_timeout = other.idle_timeout;
    this->hard_timeout = other.hard_timeout;
    this->priority = other.priority;
    this->buffer_id = other.buffer_id;
    this->out_port = other.out_port;
    this->out_group = other.out_group;
    this->flags = other.flags;
    for (unsigned int i=0; i<2; i++)
        this->pad[i] = other.pad[i];
    this->match = other.match;
    delete [] this->actions;
    this->actions = (other.actions_arraysize==0) ? nullptr : new ofp_action_output[other.actions_arraysize];
    actions_arraysize = other.actions_arraysize;
    for (unsigned int i=0; i<actions_arraysize; i++)
        this->actions[i] = other.actions[i];
}

void OFP_Flow_Mod::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::openflow::Open_Flow_Message::parsimPack(b);
    doParsimPacking(b,this->cookie);
    doParsimPacking(b,this->cookie_mask);
    doParsimPacking(b,this->table_id);
    doParsimPacking(b,this->command);
    doParsimPacking(b,this->idle_timeout);
    doParsimPacking(b,this->hard_timeout);
    doParsimPacking(b,this->priority);
    doParsimPacking(b,this->buffer_id);
    doParsimPacking(b,this->out_port);
    doParsimPacking(b,this->out_group);
    doParsimPacking(b,this->flags);
    doParsimArrayPacking(b,this->pad,2);
    doParsimPacking(b,this->match);
    b->pack(actions_arraysize);
    doParsimArrayPacking(b,this->actions,actions_arraysize);
}

void OFP_Flow_Mod::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::openflow::Open_Flow_Message::parsimUnpack(b);
    doParsimUnpacking(b,this->cookie);
    doParsimUnpacking(b,this->cookie_mask);
    doParsimUnpacking(b,this->table_id);
    doParsimUnpacking(b,this->command);
    doParsimUnpacking(b,this->idle_timeout);
    doParsimUnpacking(b,this->hard_timeout);
    doParsimUnpacking(b,this->priority);
    doParsimUnpacking(b,this->buffer_id);
    doParsimUnpacking(b,this->out_port);
    doParsimUnpacking(b,this->out_group);
    doParsimUnpacking(b,this->flags);
    doParsimArrayUnpacking(b,this->pad,2);
    doParsimUnpacking(b,this->match);
    delete [] this->actions;
    b->unpack(actions_arraysize);
    if (actions_arraysize==0) {
        this->actions = 0;
    } else {
        this->actions = new ofp_action_output[actions_arraysize];
        doParsimArrayUnpacking(b,this->actions,actions_arraysize);
    }
}

uint64_t OFP_Flow_Mod::getCookie() const
{
    return this->cookie;
}

void OFP_Flow_Mod::setCookie(uint64_t cookie)
{
    this->cookie = cookie;
}

uint64_t OFP_Flow_Mod::getCookie_mask() const
{
    return this->cookie_mask;
}

void OFP_Flow_Mod::setCookie_mask(uint64_t cookie_mask)
{
    this->cookie_mask = cookie_mask;
}

uint8_t OFP_Flow_Mod::getTable_id() const
{
    return this->table_id;
}

void OFP_Flow_Mod::setTable_id(uint8_t table_id)
{
    this->table_id = table_id;
}

uint8_t OFP_Flow_Mod::getCommand() const
{
    return this->command;
}

void OFP_Flow_Mod::setCommand(uint8_t command)
{
    this->command = command;
}

uint16_t OFP_Flow_Mod::getIdle_timeout() const
{
    return this->idle_timeout;
}

void OFP_Flow_Mod::setIdle_timeout(uint16_t idle_timeout)
{
    this->idle_timeout = idle_timeout;
}

uint16_t OFP_Flow_Mod::getHard_timeout() const
{
    return this->hard_timeout;
}

void OFP_Flow_Mod::setHard_timeout(uint16_t hard_timeout)
{
    this->hard_timeout = hard_timeout;
}

uint16_t OFP_Flow_Mod::getPriority() const
{
    return this->priority;
}

void OFP_Flow_Mod::setPriority(uint16_t priority)
{
    this->priority = priority;
}

uint32_t OFP_Flow_Mod::getBuffer_id() const
{
    return this->buffer_id;
}

void OFP_Flow_Mod::setBuffer_id(uint32_t buffer_id)
{
    this->buffer_id = buffer_id;
}

uint32_t OFP_Flow_Mod::getOut_port() const
{
    return this->out_port;
}

void OFP_Flow_Mod::setOut_port(uint32_t out_port)
{
    this->out_port = out_port;
}

uint32_t OFP_Flow_Mod::getOut_group() const
{
    return this->out_group;
}

void OFP_Flow_Mod::setOut_group(uint32_t out_group)
{
    this->out_group = out_group;
}

uint16_t OFP_Flow_Mod::getFlags() const
{
    return this->flags;
}

void OFP_Flow_Mod::setFlags(uint16_t flags)
{
    this->flags = flags;
}

unsigned int OFP_Flow_Mod::getPadArraySize() const
{
    return 2;
}

uint8_t OFP_Flow_Mod::getPad(unsigned int k) const
{
    if (k>=2) throw omnetpp::cRuntimeError("Array of size 2 indexed by %lu", (unsigned long)k);
    return this->pad[k];
}

void OFP_Flow_Mod::setPad(unsigned int k, uint8_t pad)
{
    if (k>=2) throw omnetpp::cRuntimeError("Array of size 2 indexed by %lu", (unsigned long)k);
    this->pad[k] = pad;
}

oxm_basic_match& OFP_Flow_Mod::getMatch()
{
    return this->match;
}

void OFP_Flow_Mod::setMatch(const oxm_basic_match& match)
{
    this->match = match;
}

void OFP_Flow_Mod::setActionsArraySize(unsigned int size)
{
    ofp_action_output *actions2 = (size==0) ? nullptr : new ofp_action_output[size];
    unsigned int sz = actions_arraysize < size ? actions_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        actions2[i] = this->actions[i];
    actions_arraysize = size;
    delete [] this->actions;
    this->actions = actions2;
}

unsigned int OFP_Flow_Mod::getActionsArraySize() const
{
    return actions_arraysize;
}

ofp_action_output& OFP_Flow_Mod::getActions(unsigned int k)
{
    if (k>=actions_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", actions_arraysize, k);
    return this->actions[k];
}

void OFP_Flow_Mod::setActions(unsigned int k, const ofp_action_output& actions)
{
    if (k>=actions_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", actions_arraysize, k);
    this->actions[k] = actions;
}

class OFP_Flow_ModDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OFP_Flow_ModDescriptor();
    virtual ~OFP_Flow_ModDescriptor();

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

Register_ClassDescriptor(OFP_Flow_ModDescriptor)

OFP_Flow_ModDescriptor::OFP_Flow_ModDescriptor() : omnetpp::cClassDescriptor("openflow::OFP_Flow_Mod", "openflow::Open_Flow_Message")
{
    propertynames = nullptr;
}

OFP_Flow_ModDescriptor::~OFP_Flow_ModDescriptor()
{
    delete[] propertynames;
}

bool OFP_Flow_ModDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OFP_Flow_Mod *>(obj)!=nullptr;
}

const char **OFP_Flow_ModDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OFP_Flow_ModDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OFP_Flow_ModDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 14+basedesc->getFieldCount() : 14;
}

unsigned int OFP_Flow_ModDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<14) ? fieldTypeFlags[field] : 0;
}

const char *OFP_Flow_ModDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cookie",
        "cookie_mask",
        "table_id",
        "command",
        "idle_timeout",
        "hard_timeout",
        "priority",
        "buffer_id",
        "out_port",
        "out_group",
        "flags",
        "pad",
        "match",
        "actions",
    };
    return (field>=0 && field<14) ? fieldNames[field] : nullptr;
}

int OFP_Flow_ModDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cookie")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cookie_mask")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "table_id")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "command")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "idle_timeout")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hard_timeout")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+6;
    if (fieldName[0]=='b' && strcmp(fieldName, "buffer_id")==0) return base+7;
    if (fieldName[0]=='o' && strcmp(fieldName, "out_port")==0) return base+8;
    if (fieldName[0]=='o' && strcmp(fieldName, "out_group")==0) return base+9;
    if (fieldName[0]=='f' && strcmp(fieldName, "flags")==0) return base+10;
    if (fieldName[0]=='p' && strcmp(fieldName, "pad")==0) return base+11;
    if (fieldName[0]=='m' && strcmp(fieldName, "match")==0) return base+12;
    if (fieldName[0]=='a' && strcmp(fieldName, "actions")==0) return base+13;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OFP_Flow_ModDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",
        "uint64_t",
        "uint8_t",
        "uint8_t",
        "uint16_t",
        "uint16_t",
        "uint16_t",
        "uint32_t",
        "uint32_t",
        "uint32_t",
        "uint16_t",
        "uint8_t",
        "oxm_basic_match",
        "ofp_action_output",
    };
    return (field>=0 && field<14) ? fieldTypeStrings[field] : nullptr;
}

const char **OFP_Flow_ModDescriptor::getFieldPropertyNames(int field) const
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

const char *OFP_Flow_ModDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OFP_Flow_ModDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OFP_Flow_Mod *pp = (OFP_Flow_Mod *)object; (void)pp;
    switch (field) {
        case 11: return 2;
        case 13: return pp->getActionsArraySize();
        default: return 0;
    }
}

const char *OFP_Flow_ModDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OFP_Flow_Mod *pp = (OFP_Flow_Mod *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OFP_Flow_ModDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OFP_Flow_Mod *pp = (OFP_Flow_Mod *)object; (void)pp;
    switch (field) {
        case 0: return uint642string(pp->getCookie());
        case 1: return uint642string(pp->getCookie_mask());
        case 2: return ulong2string(pp->getTable_id());
        case 3: return ulong2string(pp->getCommand());
        case 4: return ulong2string(pp->getIdle_timeout());
        case 5: return ulong2string(pp->getHard_timeout());
        case 6: return ulong2string(pp->getPriority());
        case 7: return ulong2string(pp->getBuffer_id());
        case 8: return ulong2string(pp->getOut_port());
        case 9: return ulong2string(pp->getOut_group());
        case 10: return ulong2string(pp->getFlags());
        case 11: return ulong2string(pp->getPad(i));
        case 12: {std::stringstream out; out << pp->getMatch(); return out.str();}
        case 13: {std::stringstream out; out << pp->getActions(i); return out.str();}
        default: return "";
    }
}

bool OFP_Flow_ModDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OFP_Flow_Mod *pp = (OFP_Flow_Mod *)object; (void)pp;
    switch (field) {
        case 0: pp->setCookie(string2uint64(value)); return true;
        case 1: pp->setCookie_mask(string2uint64(value)); return true;
        case 2: pp->setTable_id(string2ulong(value)); return true;
        case 3: pp->setCommand(string2ulong(value)); return true;
        case 4: pp->setIdle_timeout(string2ulong(value)); return true;
        case 5: pp->setHard_timeout(string2ulong(value)); return true;
        case 6: pp->setPriority(string2ulong(value)); return true;
        case 7: pp->setBuffer_id(string2ulong(value)); return true;
        case 8: pp->setOut_port(string2ulong(value)); return true;
        case 9: pp->setOut_group(string2ulong(value)); return true;
        case 10: pp->setFlags(string2ulong(value)); return true;
        case 11: pp->setPad(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *OFP_Flow_ModDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 12: return omnetpp::opp_typename(typeid(oxm_basic_match));
        case 13: return omnetpp::opp_typename(typeid(ofp_action_output));
        default: return nullptr;
    };
}

void *OFP_Flow_ModDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OFP_Flow_Mod *pp = (OFP_Flow_Mod *)object; (void)pp;
    switch (field) {
        case 12: return (void *)(&pp->getMatch()); break;
        case 13: return (void *)(&pp->getActions(i)); break;
        default: return nullptr;
    }
}

} // namespace openflow

