

/*18*//*<bdd86>*/typedef struct _usb_core_ctrl usb_core_ctrl_t;

/*185*//*<bf551>*/struct _usb_mem_attr {
    char* path; //0
    uint32_t flags; //4
    //8
};


/*191*//*<bf576>*/struct _usb_core_attr {
    uint32_t flags; //0
    uint32_t mode; //4
    int verbosity; //8
    char* dll_prefix; //12 = 0xc
    int prio; //16 = 0x10
    int prio_enum; //20 = 0x14
    int prio_timer; //24 = 0x18
    int prio_usbmgr; //28 = 0x1c
    int dflt_timeout; //32 = 0x20
    int enum_retry; //36 = 0x24
    struct _usb_mem_attr attr_mem; //40 = 0x28
    //48
};


/*203*//*<bf607>*/typedef struct _usb_core_attr usb_core_attr_t;


/*206*//*<bdd91>*/struct _usb_core_ctrl {
    obj_sync_t sync; //0
    uint32_t flags; //36 = 0x24
    int pci_hdl; //40 = 0x28
    usb_core_attr_t attr; //44 = 0x2c +0x30 = 0x5c
    /*<bf617>*/struct usb_memchunk_ctrl* memchunk; //92 = 0x5c
    /*<bf617>*/struct usb_memchunk_ctrl* memchunk_cached; //96 = 0x60
    pthread_rwlock_t usb_rwlock; //100 = 0x64
    pthread_mutex_t usb_mutex; //148 = 0x94
    pthread_mutex_t usb_mmutex; //156 = 0x9c
    pthread_mutex_t mutex; //164 = 0xa4
    obj_pool_t* obj_cleanup_pool; //172 = 0xac
    obj_pool_t* cpool; //176 = 0xb0
    obj_pool_t* bpool; //180 = 0xb4
    obj_pool_t* dpool; //184 = 0xb8
    obj_pool_t* surb_pool; //188 = 0xbc
    /*<bea42>*/struct _timeout_ctrl* timeout_ctrl; //192 = 0xc0
    struct sigevent timer_usb; //196 = 0xc4
    struct sigevent timer_enum; //212 = 0xd4
    //TODO!!!
    //264
};

