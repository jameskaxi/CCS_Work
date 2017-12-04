/*!
 * File generated by platform wizard. DO NOT MODIFY
 *
 */

metaonly module Platform inherits xdc.platform.IPlatform {

    config ti.platforms.generic.Platform.Instance CPU =
        ti.platforms.generic.Platform.create("CPU", {
            clockRate:      1000,                                       
            catalogName:    "ti.catalog.c6000",
            deviceName:     "TMS320C6678",
            customMemoryMap:
           [          
                ["MSMCSRAM", 
                     {
                        name: "MSMCSRAM",
                        base: 0x0c000000,                    
                        len: 0x00400000,                    
                        space: "code/data",
                        access: "RWX",
                     }
                ],
                ["L1DSRAM", 
                     {
                        name: "L1DSRAM",
                        base: 0x00f00000,                    
                        len: 0x00008000,                    
                        space: "data",
                        access: "RW",
                     }
                ],
                ["L1PSRAM", 
                     {
                        name: "L1PSRAM",
                        base: 0x00e00000,                    
                        len: 0x00008000,                    
                        space: "code",
                        access: "RWX",
                     }
                ],
                ["L2SRAM", 
                     {
                        name: "L2SRAM",
                        base: 0x00800000,                    
                        len: 0x00080000,                    
                        space: "code/data",
                        access: "RWX",
                     }
                ],
                ["DDR3", 
                     {
                        name: "DDR3",
                        base: 0x80000000,                    
                        len: 0x20000000,                    
                        space: "code/data",
                        access: "RWX",
                     }
                ],
           ],
          l2Mode:"0k",
          l1PMode:"32k",
          l1DMode:"32k",

    });
    
instance :
    
    override config string codeMemory  = "MSMCSRAM";   
    override config string dataMemory  = "MSMCSRAM";                                
    override config string stackMemory = "L2SRAM";
    
}
