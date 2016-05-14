#pragma once
#ifndef __OFFSET_INCLUIDO
#define __OFFSET_INCLUIDO

#define I_offsetof(s_name, s_member) (size_t)&(((s_name *)0)->s_member)

#define AtrInfo(s_name,s_member) \
        I_offsetof(s_name,s_member),sizeof(s_name::s_member)

#define ADI(s_name,s_member) \
        #s_member,AtrInfo(s_name,s_member)
#endif
