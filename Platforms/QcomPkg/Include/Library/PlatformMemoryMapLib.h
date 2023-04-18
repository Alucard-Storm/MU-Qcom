#ifndef _PLATFORM_MEMORY_MAP_LIB_H_
#define _PLATFORM_MEMORY_MAP_LIB_H_

#include <PiPei.h>

#include <Library/ArmLib.h>
#include <Library/HobLib.h>
#include <Library/MemoryAllocationLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 128

/* Below flag is used for system memory */
#define SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES                               \
  EFI_RESOURCE_ATTRIBUTE_PRESENT | EFI_RESOURCE_ATTRIBUTE_INITIALIZED |        \
      EFI_RESOURCE_ATTRIBUTE_TESTED | EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |     \
      EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |                               \
      EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |                         \
      EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE |                            \
      EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE |                           \
      EFI_RESOURCE_ATTRIBUTE_READ_PROTECTABLE |                                \
      EFI_RESOURCE_ATTRIBUTE_WRITE_PROTECTABLE

typedef enum { NoHob, AddMem, AddDev, HobOnlyNoCacheSetting, AllocOnly, AddDynamicMem, MaxMem } DeviceMemoryAddHob;

#define MEMORY_REGION_NAME_MAX_LENGTH 32

typedef struct {
  CHAR8                        Name[MEMORY_REGION_NAME_MAX_LENGTH];
  EFI_PHYSICAL_ADDRESS         Address;
  UINT64                       Length;
  DeviceMemoryAddHob           HobOption;
  EFI_RESOURCE_TYPE            ResourceType;
  EFI_RESOURCE_ATTRIBUTE_TYPE  ResourceAttribute;
  EFI_MEMORY_TYPE              MemoryType;
  ARM_MEMORY_REGION_ATTRIBUTES ArmAttributes;
} ARM_MEMORY_REGION_DESCRIPTOR_EX, *PARM_MEMORY_REGION_DESCRIPTOR_EX;

#define FIRMWARE_DEV EFI_RESOURCE_FIRMWARE_DEVICE
#define IO EFI_RESOURCE_IO
#define IO_RES EFI_RESOURCE_IO_RESERVED
#define MEM_RES EFI_RESOURCE_MEMORY_RESERVED
#define MMAP_IO EFI_RESOURCE_MEMORY_MAPPED_IO
#define MMAP_IO_PORT EFI_RESOURCE_MEMORY_MAPPED_IO_PORT
#define SYS_MEM EFI_RESOURCE_SYSTEM_MEMORY

#define EXECUTION_PROTECTED EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTED
#define INITIALIZED EFI_RESOURCE_ATTRIBUTE_INITIALIZED
#define PRESENT EFI_RESOURCE_ATTRIBUTE_PRESENT
#define PROTECTED EFI_RESOURCE_ATTRIBUTE_READ_PROTECTED
#define SYS_MEM_CAP SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES
#define SYS_MEM_CAP_XN (SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES | EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTED)
#define TESTED EFI_RESOURCE_ATTRIBUTE_TESTED
#define UNCACHEABLE EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE
#define WRITE_COMBINEABLE EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE
#define WRITE_PROTECTED EFI_RESOURCE_ATTRIBUTE_WRITE_PROTECTED
//#define WRITE_THROUGH EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE

#define ACPI_NVS EfiACPIMemoryNVS
#define ACPIReclaim EfiACPIReclaimMemory
#define BsCode EfiBootServicesCode
#define BsData EfiBootServicesData
#define Conv EfiConventionalMemory
#define LdCode EfiLoaderCode
#define LdData EfiLoaderData
#define MaxMem EfiMaxMemoryType
#define MmIO EfiMemoryMappedIO
#define MmIOPort EfiMemoryMappedIOPortSpace
#define PalCode EfiPalCode
#define Reserv EfiReservedMemoryType
#define RtCode EfiRuntimeServicesCode
#define RtData EfiRuntimeServicesData
#define Unusable EfiUnusableMemory

#define DEVICE ARM_MEMORY_REGION_ATTRIBUTE_DEVICE
#define NS_DEVICE ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE
#define NS_UNCACHED_UNBUFFERED ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_UNCACHED_UNBUFFERED
#define NS_WRITE_BACK ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_WRITE_BACK
#define NS_WRITE_THROUGH ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_WRITE_THROUGH
#define UNCACHED_UNBUFFERED ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED
#define UNCACHED_UNBUFFERED_XN ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED
#define WRITE_BACK ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK
#define WRITE_BACK_XN ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK
#define WRITE_THROUGH ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH
#define WRITE_THROUGH_XN ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH

ARM_MEMORY_REGION_DESCRIPTOR_EX* GetPlatformMemoryMap();

#endif /* _PLATFORM_MEMORY_MAP_LIB_H_ */
