#line 1 "block.c"

#line 1 "C:\\bitstream\\serv\\libcon\\base/std_def.h"




#line 1 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"





	
	
	typedef __int64				int64_t;
	typedef unsigned __int64	uint64_t;
	

	

#line 15 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"
		
		
		
		
	#line 20 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"
































#line 53 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"


typedef	void		   void_func();
typedef	void_func	   *void_func_ptr;





typedef enum
{
	NO_DECORATION = 0,
	MSVC_STDCALL_32 = 1,
	MSVC_CDECL_32 = 2,
	GCC_STDCALL_32 = 3,
	GCC_CDECL_32 = 4
}mod_name_decoration_t;




#line 75 "c:\\bitstream\\serv\\libcon\\base\\std_base.h"
#line 6 "C:\\bitstream\\serv\\libcon\\base/std_def.h"
	























#line 31 "C:\\bitstream\\serv\\libcon\\base/std_def.h"
	
	typedef unsigned int	size_t;
	typedef int64_t			ctime_t;

	typedef int				ptrdiff_t;
	


	

	
		
	#line 44 "C:\\bitstream\\serv\\libcon\\base/std_def.h"
	
	
		
		
		
		


		
		
		

		
		
		
		
		
		
		
		
	#line 65 "C:\\bitstream\\serv\\libcon\\base/std_def.h"
#line 66 "C:\\bitstream\\serv\\libcon\\base/std_def.h"

typedef union
{
	struct {
		uint64_t	val;
	}uint64;
	struct {
		unsigned int ints[2];
	}uint32;
}large_uint_t;


#line 79 "C:\\bitstream\\serv\\libcon\\base/std_def.h"

#line 3 "block.c"
#line 1 "C:\\bitstream\\serv\\libcon\\base/std_mem.h"


#line 4 "C:\\bitstream\\serv\\libcon\\base/std_mem.h"

typedef void			*mem_ptr;
typedef const void		*const_mem_ptr;

typedef size_t		   mem_size;

struct big64
{
	union N
	{
		uint64_t v64;
		unsigned int v[2];
	}n;

	union N m;
};

struct big128
{
	unsigned int v[4];
};





		
__declspec(dllimport) mem_ptr		 memcpy_c				(mem_ptr dst_ptr,const_mem_ptr src_ptr,mem_size size);


__declspec(dllimport) mem_ptr		 memmove_c			(mem_ptr dst_ptr,const_mem_ptr src_ptr,mem_size size);
__declspec(dllimport) mem_ptr		 memset_c				(mem_ptr ptr,unsigned char v,mem_size size);
__declspec(dllimport) mem_ptr		 memset_32_c			(mem_ptr ptr,unsigned int v,mem_size size);
__declspec(dllimport) int			 memcmp_c				(const_mem_ptr ptr1,const_mem_ptr ptr2,size_t size);
__declspec(dllimport) const_mem_ptr	 memchr_c				(const_mem_ptr ptr,int value,mem_size size);
__declspec(dllimport) size_t			 memchr_32_c			(const_mem_ptr ptr,unsigned int value,mem_size size);
__declspec(dllimport) void			 qsort_c				(mem_ptr base, mem_size num, mem_size width,  int ( *comp)(const_mem_ptr,const_mem_ptr));

__declspec(dllimport) mem_ptr		 realloc_c			(mem_ptr ptr,mem_size sz);
__declspec(dllimport) void			 free_c				(mem_ptr ptr);
__declspec(dllimport) mem_ptr		 malloc_c				(mem_size sz);
__declspec(dllimport) mem_ptr		 calloc_c				(mem_size sz,mem_size blk);
__declspec(dllimport) mem_ptr		 get_next_aligned_ptr (mem_ptr ptr);

__declspec(dllimport) uint64_t		 mul64(uint64_t a, uint64_t b);
__declspec(dllimport) uint64_t		 muldiv64(uint64_t a, uint64_t b, uint64_t c);
__declspec(dllimport) uint64_t		 shl64(uint64_t a, unsigned char n);
__declspec(dllimport) uint64_t		 shr64(uint64_t a, unsigned char n);
__declspec(dllimport) double			 exp_c(double a);
__declspec(dllimport) void			 big128_mul(unsigned int x, struct big64 y, struct big128 *out);




__declspec(dllimport) unsigned int	__cdecl		compare_z_exchange_c(volatile unsigned int *data, unsigned int new_value);
__declspec(dllimport) unsigned int	__cdecl		compare_exchange_c  (volatile unsigned int *data,unsigned int value, unsigned int new_value);


__declspec(dllimport) char			__cdecl		fetch_add_c(volatile unsigned int *data, volatile char new_value);
__declspec(dllimport) char			__cdecl		mfence_c();


__declspec(dllimport) unsigned int	__cdecl		calc_crc32_c(const char *, size_t);









#line 77 "C:\\bitstream\\serv\\libcon\\base/std_mem.h"



#line 4 "block.c"
#line 1 "C:\\bitstream\\serv\\libcon\\base/mem_base.h"









typedef struct
{
	volatile  mem_ptr zone;
}mem_zone_ref;

typedef struct
{
	const_mem_ptr zone;
}mem_zone_const_ref;

typedef mem_zone_ref			*mem_zone_ref_ptr;
typedef const mem_zone_ref		*mem_zone_ref_const_ptr;
typedef mem_zone_const_ref		*mem_zone_const_ref_ptr;

typedef int  zone_free_func(mem_zone_ref_ptr zone_ref, unsigned int scan_id);
typedef  zone_free_func	*zone_free_func_ptr;

typedef int  thread_func(mem_zone_ref_ptr p,unsigned int *status);
typedef thread_func *thread_func_ptr;

typedef enum {MEM_TYPE_DATA = 1,MEM_TYPE_TREE = 2}mem_area_type_t;
	
typedef int				vec_2s_t[2];
typedef unsigned int	vec_2_t[2];
typedef unsigned char	vec_4uc_t[4];

struct gfx_rect
{
	vec_2s_t	pos;
	vec_2_t		size;
};





__declspec(dllimport) void			 init_default_mem_area	(unsigned int size);
__declspec(dllimport) unsigned int	 mem_area_enable_sem		(unsigned int area_id);
__declspec(dllimport) unsigned int	 init_new_mem_area		(mem_ptr phys_start,	mem_ptr phys_end,mem_area_type_t type);
__declspec(dllimport) unsigned int	 free_mem_area			(unsigned int area_id);
__declspec(dllimport) unsigned int	 allocate_new_zone		(unsigned int area_id,	mem_size zone_size,	mem_zone_ref *zone_ref);
__declspec(dllimport) unsigned int	 allocate_new_empty_zone	(unsigned int area_id,mem_zone_ref *zone_ref);
__declspec(dllimport) int			 expand_zone				(mem_zone_ref *ref,mem_size new_size);
__declspec(dllimport) int 			 realloc_zone				(mem_zone_ref *zone_ref,mem_size new_size);
__declspec(dllimport) void 			 empty_trash				();
		
__declspec(dllimport) void			 copy_zone_ref			(mem_zone_ref_ptr dest_zone_ref,mem_zone_ref_const_ptr zone_ref);
__declspec(dllimport) void			 copy_zone_const_ref		(mem_zone_const_ref_ptr dest_zone_ref,mem_zone_const_ref_ptr zone_ref);
__declspec(dllimport) unsigned int	 get_zone_area_type		(mem_zone_ref_const_ptr zone);
__declspec(dllimport) unsigned int	 create_zone_ref			(mem_zone_ref *dest_zone_ref,mem_ptr ptr,mem_size size);
__declspec(dllimport) void			 init_mem_system			();
__declspec(dllimport) size_t			 dump_mem_used			(unsigned int area_id);
__declspec(dllimport) size_t			 dump_mem_used_after		(unsigned int area_id, unsigned int time, mem_zone_ref *outs, size_t nOuts);


__declspec(dllimport) int			  get_shared_slot			(mem_zone_ref_ptr shared_zone, mem_zone_ref_ptr *zone_ptr);
__declspec(dllimport) int			 release_shared_slot		(mem_zone_ref_ptr zone_ptr);

__declspec(dllimport) mem_ptr		 get_zone_ptr				(mem_zone_ref_const_ptr ref,mem_size ofset);
__declspec(dllimport) mem_size		 get_zone_size			(mem_zone_ref_const_ptr ref);
__declspec(dllimport) unsigned int	 do_mark_sweep			(unsigned int area_id, unsigned int delay);
__declspec(dllimport) void			 mark_zone				(mem_ptr zone, unsigned int scan_id);

__declspec(dllimport) unsigned int	 find_zones_used			(unsigned int area_id);
__declspec(dllimport) void			 do_gdt_real_mode			(mem_ptr new_gdt);
__declspec(dllimport) unsigned int	 get_zone_numref			(mem_zone_ref *zone_ref);
__declspec(dllimport) unsigned int	 area_type				(unsigned int area_id);

__declspec(dllimport) void			 swap_zone_ref					(mem_zone_ref_ptr dest_zone_ref, mem_zone_ref_ptr src_zone_ref);



__declspec(dllimport) int			 set_mem_area_id					(unsigned int area_id);
__declspec(dllimport) int			 set_tree_mem_area_id				(unsigned int area_id);
__declspec(dllimport) unsigned int	 get_mem_area_id					();
__declspec(dllimport) unsigned int	 get_tree_mem_area_id				();
__declspec(dllimport) int			 background_func					(thread_func_ptr func, mem_zone_ref_ptr params);


static __inline unsigned int mem_to_uint(const_mem_ptr ptr)
{
	return *((unsigned int *)&ptr);
}

static __inline unsigned short mem_to_ushort(const_mem_ptr ptr,unsigned char which)
{
	unsigned int ptr_val;
	unsigned int mask;
	unsigned short ret;
	mask	=	(0xFFFF<<which);
	ptr_val	=	*((unsigned int *)&ptr);
	ret		=	(unsigned short )((ptr_val&mask)>>which);
	return ret;
}

static __inline mem_size mem_to_size(const_mem_ptr ptr)
{
	return *((mem_size *)&ptr);
}

static __inline int mem_to_int(const_mem_ptr ptr)
{
	return *((int *)&ptr);
}


static __inline mem_ptr uint_to_mem(unsigned int val)
{
	large_uint_t val64;

	val64.uint32.ints[0]=val;
	val64.uint32.ints[1]=0;
	return ((mem_ptr )((mem_size)(val64.uint64.val)));
}

static __inline mem_ptr size_to_mem(size_t val)
{
	return ((mem_ptr )val);
}

static __inline mem_size mem_sub(const_mem_ptr base,const_mem_ptr end)
{
	mem_size	s_base,s_end;

	s_base	=	mem_to_uint(base);
	s_end	=	mem_to_uint(end);

	return (s_end-s_base);

}

static __inline mem_ptr mem_add(const_mem_ptr base,mem_size size)
{
	mem_size	s_base;

	s_base	=	mem_to_uint(base);
	s_base  =    s_base + size;
	return		size_to_mem(s_base);
}

static __inline mem_ptr mem_dec(const_mem_ptr base,mem_size size)
{
	mem_size	s_base;

	s_base	=	 mem_to_uint(base);
	s_base  =    s_base - size;
	return		size_to_mem(s_base);
}


static __inline void copy_vec4u_c	(vec_4uc_t d,const vec_4uc_t s)
{
	d[0]=s[0];
	d[1]=s[1];
	d[2]=s[2];
	d[3]=s[3];
}

__declspec(dllimport) void			  release_zone_ref	(mem_zone_ref_ptr zone_ref);
__declspec(dllimport) void			  dec_zone_ref		(mem_zone_ref_ptr zone_ref);
__declspec(dllimport) unsigned int   	inc_zone_ref		(mem_zone_ref_ptr zone_ref);
__declspec(dllimport) mem_size	    	set_zone_free		(mem_zone_ref_ptr ref, zone_free_func_ptr	free_func);









#line 5 "block.c"
#line 1 "C:\\bitstream\\serv\\libcon\\base/std_str.h"




__declspec(dllimport) char *			 strncpy_c				(char *string,const char *src_string,size_t		 cnt);
__declspec(dllimport) char *			 strncpy_cs				(char *string,size_t str_len,const char *src_string,size_t cnt);

__declspec(dllimport) int			 strcpy_cs				(char *string,size_t size,const char *src_string);
__declspec(dllimport) char *			 strcpy_c					(char *string,const char *src_string);
__declspec(dllimport) int			 strcat_cs				(char *string,size_t size,const char *src_string);
__declspec(dllimport) int			 strcat_intval_s			(char *string,size_t size,const char *name,int val,int radix);
__declspec(dllimport) int			 strcat_uintval_s			(char *string,size_t size,const char *name,unsigned int val,int radix);
__declspec(dllimport) int			 strcat_escaped_s			(char *string,size_t size,const char *src_string);
__declspec(dllimport) char *			 str_replace_char_c		(char *string, char c1, char c2);
__declspec(dllimport) int			 strncat_c				(char *string,const char *src_string,size_t max);
__declspec(dllimport) int			 strcat_c					(char *string,const char *src_string);
__declspec(dllimport) int			 strcmp_c					(const char *string1,const char *string2);
__declspec(dllimport) int			 strncmp_c				(const char *string1,const char *string2,size_t len);
__declspec(dllimport) int			 strincmp_c				(const char *string1,const char *string2,size_t len);
__declspec(dllimport) int			 stricmp_c				(const char *string1,const char *string2);

__declspec(dllimport) const char	*	 strrchr_c				(const char *src,int car);
__declspec(dllimport) size_t 		 strlen_c					(const char *string);
__declspec(dllimport) size_t			 strlpos_c				(const char *string,size_t ofset,char c);
__declspec(dllimport) size_t			 strrpos_c				(const char *string,char c);

__declspec(dllimport) int			 itoa_s					(int value, char *string,size_t len, int radix);
__declspec(dllimport) int			 uitoa_s					(size_t value, char *string, size_t len, int radix);
__declspec(dllimport) int			 luitoa_s					(uint64_t value, char *string, size_t len, int radix);
__declspec(dllimport) int			 litoa_s					(int64_t value, char *str, size_t len, int base);

__declspec(dllimport) long			 strtol_c					(const char *nptr, char **endptr,int base);
__declspec(dllimport) int64_t		 strtoll_c				(const char *nptr, char **endptr, int base);
__declspec(dllimport) unsigned long	 strtoul_c				(const char *nptr, char **endptr, int base);
__declspec(dllimport) short			 strtos_c					(const char *nptr, char **endptr, int base);
__declspec(dllimport) long			 atol_c					(const char *str ); 
__declspec(dllimport) void			 dtoll_c					(double dAmount, uint64_t *nAmount);
__declspec(dllimport) const char *	 strstr_c					(const char *buf, const char *sub);
__declspec(dllimport) unsigned int	 get_new_kern_log_id		(const char *pref,unsigned char color);
__declspec(dllimport) void			 kernel_log				(unsigned int kern_log_id,const char *str);
__declspec(dllimport) int			 tolower_c				(int _c);
__declspec(dllimport) int			 toupper_c				(int _c);
__declspec(dllimport) int			 isprint_c				(int _c);
__declspec(dllimport) int			 isalpha_c				(int _c);
__declspec(dllimport) int			 isdigit_c				(int _c);
__declspec(dllimport) int			 isdigit_c				(int _c);
__declspec(dllimport) int			 isxdigit_c				(int _c);
__declspec(dllimport) int			 isspace_c				(int _c);
__declspec(dllimport) void			 snooze_c					(unsigned int micro_sec);
__declspec(dllimport) void			 dtoa_c					(char *buff, char conv, int bsize, int dplace, double value);
__declspec(dllimport) unsigned int	 parseDate				(const char *date);
__declspec(dllimport) void			 store_bigendian			(unsigned char *x, uint64_t u);
__declspec(dllimport) uint64_t		 load_bigendian			(const unsigned char *x);

__declspec(dllimport) void			 strtod_c					(const char *str, double *d);
__declspec(dllimport) void			 strtof_c					(const char *str, float *f);

static const char		hex_chars[]		=	{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

typedef unsigned char	ipv4_t[4];
typedef	char			bitcore_cmd_t[12];
typedef	unsigned char	hash_t[32];
typedef	char			btc_addr_t[34];
typedef	char			btc_paddr_t[52];

#line 6 "block.c"

#line 1 "C:\\bitstream\\serv\\libbase\\include\\sha256.h"

	
#line 4 "C:\\bitstream\\serv\\libbase\\include\\sha256.h"

typedef struct
{
	unsigned int total[2];      
	unsigned int state[8];      
	unsigned char buffer[64];   
	int is224;                  
}
mbedtls_sha256_context;

__declspec(dllimport) void  mbedtls_sha256_init(mbedtls_sha256_context *ctx);
__declspec(dllimport) void  mbedtls_sha256_starts(mbedtls_sha256_context *ctx, int is224);
__declspec(dllimport) void  mbedtls_sha256_update(mbedtls_sha256_context *ctx, const unsigned char *input, size_t ilen);
__declspec(dllimport) void  mbedtls_sha256_free(mbedtls_sha256_context *ctx);
__declspec(dllimport) void  mbedtls_sha256_finish(mbedtls_sha256_context *ctx, unsigned char output[32]);
__declspec(dllimport) void  mbedtls_sha256(const unsigned char *input, size_t ilen, unsigned char output[32], int is224);
__declspec(dllimport) int	  crypto_hash_sha512(unsigned char *out, const unsigned char *in, size_t inlen);
__declspec(dllimport) int	  ripemd160(const void* in, unsigned long length, void* out);
#line 8 "block.c"

#line 1 "C:\\bitstream\\serv\\libbase\\include\\crypto.h"


#line 4 "C:\\bitstream\\serv\\libbase\\include\\crypto.h"







typedef unsigned char dh_key_t[64];

typedef int				 crypto_extract_key_func	(dh_key_t pk, const dh_key_t sk);
typedef int 			 crypto_sign_open_func	(const struct string *sign, struct string *msg, const struct string *pk);

typedef crypto_sign_open_func	*crypto_sign_open_func_ptr;
typedef crypto_extract_key_func *crypto_extract_key_func_ptr;


	typedef struct string	 crypto_sign_func(const struct string *msg, const dh_key_t sk);
	typedef crypto_sign_func		*crypto_sign_func_ptr;
#line 23 "C:\\bitstream\\serv\\libbase\\include\\crypto.h"



#line 10 "block.c"
#line 1 "C:\\bitstream\\serv\\libcon\\include\\strs.h"

struct string
{
	char	*str;		
	size_t  len;		
	size_t  size;		
};


struct host_def
{
	struct string		host;		
	struct string		port_str;	
	unsigned short		port;		
};



__declspec(dllimport)		void				 init_string			(struct string *str);


__declspec(dllimport)		int 				 prepare_new_data		(struct string *str, size_t len);


__declspec(dllimport)		int					 clone_string			(struct string *str, const struct string *str1);


__declspec(dllimport)		int					 make_string			(struct string *str, const char *toto);


__declspec(dllimport)		int 				 make_string_l		(struct string *str, const char *toto, size_t len);


__declspec(dllimport)		int 				 make_string_url		(struct string *str, const char *toto, size_t len);


__declspec(dllimport)		int 				 make_string_from_url	(struct string *str, const char *toto, size_t len);


__declspec(dllimport)		int 				 make_string_from_uint(struct string *str, size_t i);


__declspec(dllimport)		size_t				 cat_string			(struct string *str, const struct string *src);


__declspec(dllimport)		int					 strcat_uint			(struct string *str, size_t i);


__declspec(dllimport)		int					 strcat_float			(struct string *str, double f);


__declspec(dllimport)		int 				 strcat_int			(struct string *str, int i);


__declspec(dllimport)		int 				 cat_cstring			(struct string *str, const char *src);


__declspec(dllimport)		int 				 cat_ncstring			(struct string *str, const char *src, size_t src_len);


__declspec(dllimport)		int					 cat_ncstring_p		(struct string *str, const char *src, size_t src_len);


__declspec(dllimport)		int					 cat_cstring_p		(struct string *str, const char *src);


__declspec(dllimport)		int 				 make_cstring			(const struct string *str, char *toto, size_t len);


__declspec(dllimport)		void				 free_string			(struct string *str);


__declspec(dllimport)		struct host_def *	 make_host_def		(const char *host, unsigned short port);


__declspec(dllimport)		struct host_def	*	 make_host_def_url	(const struct string *url, struct string *path);


__declspec(dllimport)		void				 copy_host_def		(struct host_def *dhost, const struct host_def *host);


__declspec(dllimport)		void				 free_host_def		(struct host_def *host);


__declspec(dllimport)		void				 cat_tag				(struct string *str, const char *tag, const char *val);


__declspec(dllimport)		int					 do_zip				(const char *fileName, struct string *initial_data, const char **files, size_t nFiles, struct string *zipData);


__declspec(dllimport)		int					 str_end_with			(const struct string *str, const char *end);

__declspec(dllimport)		int					 str_start_with		(const struct string *str, const char *start);

__declspec(dllimport)		int					 vstr_to_str			(mem_ptr data_ptr, struct string *str);


__declspec(dllimport)		int					 find_mem_hash		(hash_t hash, unsigned char *mem_hash, unsigned int num);
#line 11 "block.c"
#line 1 "C:\\bitstream\\serv\\libbase\\include\\tree.h"
































































































































const enum op_type { CMP_E, CMP_L, CMP_G, CMPL_E, CMPL_L, CMPL_G, CMPL_N, CMP_N };

struct key_val
{
	char			key[64];
	unsigned int	kcrc;
	enum op_type	op;
	struct string	value;
};

struct node_hash_val_t
{
	unsigned int		crc;
	mem_ptr				data;
};





































































































































#line 12 "block.c"
#line 1 "C:\\bitstream\\serv\\libcon\\include\\fsio.h"




__declspec(dllimport) size_t			 file_size(const char *path);
__declspec(dllimport) int			 append_file(const char *path, const void *data, size_t data_len);
__declspec(dllimport) int			 truncate_file(const char *path, size_t ofset, const void *data, size_t data_len);
__declspec(dllimport) int			 stat_file(const char *path);
__declspec(dllimport) int			 create_dir(const char *path);
__declspec(dllimport) int			 del_dir(const char *path);
__declspec(dllimport) int			 put_file(const char *path, void *data, size_t data_len);
__declspec(dllimport) int			 get_sub_dirs(const char *path, struct string *dir_list);
__declspec(dllimport) int			 get_sub_files(const char *path, struct string *file_list);
__declspec(dllimport) int			 get_file(const char *path, unsigned char **data, size_t *data_len);
__declspec(dllimport) int			 get_file_len(const char *path, size_t size, unsigned char **data, size_t *data_len);
__declspec(dllimport) int			 get_file_chunk(const char *path, size_t ofset, unsigned char **data, size_t *data_len);

__declspec(dllimport) int			 get_hash_idx(const char *path, size_t idx, hash_t hash);
__declspec(dllimport) int			 set_home_path(const char *name);
__declspec(dllimport) int			 set_data_dir(const struct string *path,const char *name);
__declspec(dllimport) int			 set_exe_path();
__declspec(dllimport) int			 get_exe_path(struct string *outPath);
__declspec(dllimport) int			 daemonize(const char *name);
__declspec(dllimport) ctime_t		 get_time_c(void);
__declspec(dllimport) void			 get_system_time_c(ctime_t *time);
__declspec(dllimport) void			 console_print(const char *msg);
__declspec(dllimport) int			 log_output(const char *data);
__declspec(dllimport) int			 set_mem_exe(mem_zone_ref_ptr zone);
__declspec(dllimport) int			 move_file(const char *ipath,const char *opath);
__declspec(dllimport) int			 del_file(const char *path);
__declspec(dllimport) int			 set_ftime(const char *path, ctime_t time);
__declspec(dllimport) int			 get_ftime(const char *path, ctime_t *time);
__declspec(dllimport) int			 get_home_dir(struct string *path);
__declspec(dllimport) int			 set_cwd(const char *path);
__declspec(dllimport) int			 get_cwd(char *path, size_t len);
__declspec(dllimport) int			 rm_dir(const char *dir);
__declspec(dllimport) unsigned int	 get_tree_mem_area_id(void);
__declspec(dllimport) unsigned int	 get_mem_area_id(void);
__declspec(dllimport) unsigned int	 isRunning(void);
__declspec(dllimport) int  default_RNG(unsigned char *dest, size_t size);
#line 13 "block.c"
#line 1 "C:\\bitstream\\serv\\libcon\\include\\mem_stream.h"




typedef struct
{
	mem_zone_ref		data;
	mem_size			current_ptr;
	mem_size			buf_ofs;
}mem_stream;

typedef struct
{
	mem_zone_const_ref		data;
	mem_size				current_ptr;
}const_mem_stream;


__declspec(dllimport) void				mem_stream_init(mem_stream *stream, mem_zone_ref *stream_zone, mem_size buffer_ofset);
__declspec(dllimport) int				mem_stream_decomp(mem_stream *stream, unsigned int comp_size, unsigned int decomp_size);
__declspec(dllimport) unsigned char		mem_stream_read_8(mem_stream *stream);
__declspec(dllimport) unsigned char		mem_stream_peek_8(mem_stream *stream);
__declspec(dllimport) unsigned short		mem_stream_read_16(mem_stream *stream);
__declspec(dllimport) unsigned int		mem_stream_read_32(mem_stream *stream);
__declspec(dllimport) unsigned int		mem_stream_peek_32(mem_stream *stream);
__declspec(dllimport) size_t				mem_stream_read(mem_stream *stream, char *data, size_t len);
__declspec(dllimport) size_t				mem_stream_skip(mem_stream *stream, unsigned int len);
__declspec(dllimport) size_t				mem_stream_skip_to(mem_stream *stream, size_t position);
__declspec(dllimport) size_t				mem_stream_write(mem_stream *stream, unsigned char *data, size_t len);
__declspec(dllimport) size_t				mem_stream_write_8(mem_stream *stream, unsigned char data);
__declspec(dllimport) size_t				mem_stream_write_16(mem_stream *stream, unsigned short data);
__declspec(dllimport) size_t				mem_stream_write_32(mem_stream *stream, unsigned int data);
__declspec(dllimport) size_t				mem_stream_get_pos(mem_stream *stream);

__declspec(dllimport) void				mem_stream_close(mem_stream *stream);

__declspec(dllimport) int			  get_file_to_memstream(const char *path, mem_stream *stream);
#line 14 "block.c"
#line 1 "C:\\bitstream\\serv\\libcon\\include\\tpo_mod.h"







typedef struct
{
	unsigned int		crc_32;
	unsigned int		sym_addr;
	unsigned int		string_idx;
}tpo_export;

typedef struct
{
	size_t				reloc_addr;
	unsigned int		sym_addr;
}tpo_import;

typedef struct
{
	size_t				section_ptr;
	size_t				section_size;
	size_t				section_img_ofset;
	unsigned int		is_code;
	mem_zone_ref		exports_fnc;
	mem_zone_ref		imports_fnc;

}tpo_section;

typedef struct
{
	unsigned int			mod_idx;
	mod_name_decoration_t	deco_type;
	char					name[64];
	unsigned int			name_hash;
	mem_zone_ref			string_buffer_ref;
	unsigned int			string_buffer_len;
	mem_zone_ref			data_sections;
	tpo_section				sections[32];
}tpo_mod_file;

struct kern_mod_fn_t
{
	unsigned int	func_hash;
	unsigned int	func_addr;
	unsigned int	section_start_addr;
	unsigned int	string_idx;
};

struct kern_mod_t
{
	unsigned int	mod_hash;
	unsigned char	n_funcs;
	unsigned char	n_sections;
	unsigned short  fn_ofset;
	mem_ptr			mod_addr;
	mem_ptr			string_tbl;
};

typedef const tpo_mod_file *const_tpo_mod_file_ptr ;



__declspec(dllimport) void			 tpo_mod_init(tpo_mod_file *driver);

__declspec(dllimport) int			 tpo_mod_load_tpo(mem_stream *file_stream, tpo_mod_file *tpo_file, unsigned int imp_func_addr);
__declspec(dllimport) tpo_mod_file *   find_mod_ptr(unsigned int name_hash);

__declspec(dllimport) void_func_ptr	 tpo_mod_get_exp_addr(mem_stream *file_stream, const char *sym);
__declspec(dllimport) void_func_ptr	 get_tpo_mod_exp_addr_name(const tpo_mod_file *tpo_mod, const char *name, unsigned int deco_type);
__declspec(dllimport) int			 set_tpo_mod_exp_value32(const tpo_mod_file *tpo_mod, unsigned int crc_32, unsigned int value);
__declspec(dllimport) int			 set_tpo_mod_exp_value32_name(const tpo_mod_file *tpo_mod, const char *name, unsigned int value);
__declspec(dllimport) void			 register_tpo_exports(tpo_mod_file *tpo_mod, const char *mod_name);
	
__declspec(dllimport) int				run_tpo(const char *file_system, const char *file_name, tpo_mod_file *mod);
__declspec(dllimport) int				load_tpo_dll(const char *file_system, const char *file_name, tpo_mod_file *mod);
__declspec(dllimport) int				run_app(const char *file_system, const char *file_name, tpo_mod_file *mod, mem_zone_ref_ptr app_data);

__declspec(dllimport) int				 load_module(const char *file, const char *mod_name, tpo_mod_file *mod);
__declspec(dllimport) struct kern_mod_t	* tpo_mod_find(const char *name);




__declspec(dllimport) int  execute_script_mod_call(tpo_mod_file		*tpo_mod, const char *method);
__declspec(dllimport) int  execute_script_mod_rcall(tpo_mod_file		*tpo_mod, const char *method, mem_zone_ref_ptr input);
__declspec(dllimport) int  execute_script_mod_rwcall(tpo_mod_file		*tpo_mod, const char *method, mem_zone_ref_ptr input, mem_zone_ref_ptr output);

typedef int  module_proc();
typedef module_proc *module_proc_ptr;


typedef int  module_rproc(mem_zone_ref_ptr input);
typedef module_rproc *module_rproc_ptr;

typedef int  module_rwproc(mem_zone_ref_ptr input, mem_zone_ref_ptr output);
typedef module_rwproc *module_rwproc_ptr;










#line 111 "C:\\bitstream\\serv\\libcon\\include\\tpo_mod.h"

__declspec(dllimport) unsigned int				sys_add_tpo_mod_func_name(const char *name, const char *fn_name, void_func_ptr addr, unsigned int deco);
__declspec(dllimport) struct kern_mod_t	* 	tpo_get_mod_entry_hash_c(unsigned int mod_hash);
__declspec(dllimport) struct kern_mod_fn_t * 	tpo_get_fn_entry_name_c(unsigned int mod_idx, unsigned int mod_hash, unsigned int str_idx, unsigned int deco_type);



typedef unsigned int	 defaut_import_func_ptr		(void *data);
typedef int			     run_func_fn					();
typedef int			     init_func_fn					(mem_zone_ref_ptr	init_data);

typedef run_func_fn *run_func_fn_ptr;
typedef init_func_fn *init_func_fn_ptr;

extern tpo_mod_file			*modz[64];
extern size_t				n_modz;

#line 15 "block.c"



#line 1 "c:\\bitstream\\serv\\block_adx\\block_api.h"




struct bin_tree;
typedef struct bin_tree node;









__declspec(dllexport)  int	 init_blocks(mem_zone_ref_ptr node_config);


__declspec(dllexport)  void	 mul_compact(unsigned int nBits, uint64_t op, hash_t hash);


__declspec(dllexport)  int	 cmp_hashle(hash_t hash1, hash_t hash2);


__declspec(dllexport) unsigned int	 calc_new_target(unsigned int nActualSpacing, unsigned int TargetSpacing, unsigned int nTargetTimespan, unsigned int pBits);


__declspec(dllexport)  int	 get_block_height();


__declspec(dllexport)  int	 get_blockreward(uint64_t block, uint64_t *block_reward);


__declspec(dllexport)  int	 get_hash_list(mem_zone_ref_ptr hdr_list, mem_zone_ref_ptr hash_list);


__declspec(dllexport)  int	 build_merkel_tree(mem_zone_ref_ptr txs, hash_t merkleRoot);


__declspec(dllexport)  int	 make_genesis_block(mem_zone_ref_ptr genesis_conf, mem_zone_ref_ptr genesis_blk);


__declspec(dllexport) int	   get_tx_output(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr vout);


__declspec(dllexport)  int	   get_insig_info(const struct string *script, struct string *sign, struct string *pubk, unsigned char *hash_type);


__declspec(dllexport)  int	   parse_sig_seq(const struct string *sign_seq, struct string *sign, unsigned char *hashtype, int rev);


__declspec(dllexport)  int		serialize_script(mem_zone_ref_const_ptr script_node, struct string *script);


__declspec(dllexport)  int		create_null_tx(mem_zone_ref_ptr tx, unsigned int time, unsigned int block_height);


__declspec(dllexport)  int		is_tx_null(mem_zone_ref_const_ptr tx);


__declspec(dllexport)  int		is_vout_null(mem_zone_ref_const_ptr tx, unsigned int idx);


__declspec(dllexport)  int		new_transaction(mem_zone_ref_ptr tx, ctime_t time);


__declspec(dllexport)  int		 tx_add_output(mem_zone_ref_ptr tx, uint64_t value, const struct string *script);


__declspec(dllexport)  int		tx_add_input(mem_zone_ref_ptr tx, const hash_t tx_hash, unsigned int index,const struct string *script);


__declspec(dllexport)  int		create_payment_script(const struct string *pubk, unsigned int type, mem_zone_ref_ptr script_node);


__declspec(dllexport) int		create_payment_script_data(const struct string *pubk, unsigned int type, mem_zone_ref_ptr script_node, const unsigned char *data, size_t len);


__declspec(dllexport)  int		create_p2sh_script			(btc_addr_t addr, mem_zone_ref_ptr script_node);


__declspec(dllexport)  int		create_p2sh_script_byte		(btc_addr_t addr, mem_zone_ref_ptr script_node, unsigned char val);

__declspec(dllexport)  int		create_p2sh_script_data		(btc_addr_t addr, mem_zone_ref_ptr script_node, const unsigned char *data, size_t len);


__declspec(dllexport)  int		compute_tx_sign_hash		(mem_zone_ref_const_ptr tx, unsigned int nIn, const struct string *script, unsigned int hash_type, hash_t txh);


__declspec(dllexport)  int		check_tx_input_sig			(mem_zone_ref_const_ptr tx, unsigned int nIn, struct string *vpubK);


__declspec(dllexport)  int		check_tx_outputs			(mem_zone_ref_ptr tx, uint64_t *total, unsigned int *is_staking);


__declspec(dllexport)  int		check_tx_inputs				(mem_zone_ref_ptr tx, uint64_t *total_in, unsigned int *is_coinbase,unsigned int check_sig);



__declspec(dllexport)  int	 check_block_pow				(mem_zone_ref_ptr hdr, hash_t diff_hash);


__declspec(dllexport)  int	 check_block_sign				(const struct string *sign, const hash_t hash, const struct string *pubk);


__declspec(dllexport)  int	 get_tx_input_hash			(mem_zone_ref_ptr tx, unsigned int idx, hash_t hash);


__declspec(dllexport)  int	 get_tx_output_amount			(mem_zone_ref_ptr tx, unsigned int idx, uint64_t *amount);


__declspec(dllexport)  int	 get_tx_output_addr			(const hash_t tx_hash, unsigned int idx, btc_addr_t addr);


__declspec(dllexport)  int	 tx_sign						(mem_zone_ref_const_ptr tx, unsigned int nIn, unsigned int hashType, const struct string *sign, const struct string *inPubKey);


__declspec(dllexport) int		compute_block_hash			(mem_zone_ref_ptr block, hash_t hash);


__declspec(dllexport) int		compute_block_pow			(mem_zone_ref_ptr block, hash_t hash);


__declspec(dllexport)  int	 block_compute_pow_target		(mem_zone_ref_ptr ActualSpacing, mem_zone_ref_ptr diff);


__declspec(dllexport)  int	 compute_tx_hash				(mem_zone_ref_ptr tx, hash_t hash);


__declspec(dllexport) int		get_block_version			(unsigned int *v);


__declspec(dllexport) int		blk_check_sign				(const struct string *sign, const struct string *pubk, const hash_t hash);


__declspec(dllexport)  int	 check_tx_list				(mem_zone_ref_ptr tx_list, uint64_t block_reward,hash_t merkle,unsigned int check_sig);



__declspec(dllexport)  int	 find_inputs					(mem_zone_ref_ptr tx_list, hash_t txid, unsigned int oidx);


__declspec(dllexport) int		get_tx_input				(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr vin);



__declspec(dllexport) unsigned int	 SetCompact			(unsigned int bits, hash_t out);



__declspec(dllexport) int  check_utxo						(const char *tx, unsigned int oidx);


__declspec(dllexport) int  dump_tx_infos					(mem_zone_ref_ptr tx);
__declspec(dllexport) int  dump_txh_infos					(const char *hash);


__declspec(dllexport)  int	 get_block_tree				(node **blktree);

__declspec(dllexport)  int	 get_tx_data					(mem_zone_ref_ptr tx, mem_zone_ref_ptr txData);

__declspec(dllexport)  int	 blk_find_last_pow_block		(mem_zone_ref_ptr pindex, unsigned int *block_time);
__declspec(dllexport)  int	 block_pow					(uint64_t height);
__declspec(dllexport)  int	 extract_key					(dh_key_t priv, dh_key_t pub);
__declspec(dllexport)  int	 remove_tx_index				(hash_t tx_hash);

__declspec(dllexport) int  set_root_app					(mem_zone_ref_ptr tx);
__declspec(dllexport) int  get_root_app					(mem_zone_ref_ptr  rootAppHash);
__declspec(dllexport) int  get_apps						(mem_zone_ref_ptr Apps);

__declspec(dllexport) int  get_root_app_addr				(mem_zone_ref_ptr rootAppAddr);

__declspec(dllexport) int  is_app_root					(mem_zone_ref_ptr tx);

__declspec(dllexport) int  blk_load_app_root				();

__declspec(dllexport) int  blk_load_apps					(mem_zone_ref_ptr apps);

__declspec(dllexport) int  make_approot_tx				(mem_zone_ref_ptr tx, ctime_t time,btc_addr_t addr);

__declspec(dllexport) int  get_root_app_fee				(mem_zone_ref_ptr rootAppFees);

__declspec(dllexport) int  make_app_tx					(mem_zone_ref_ptr tx,const char *app_name,btc_addr_t appAddr);
__declspec(dllexport) int  make_app_item_tx				(mem_zone_ref_ptr tx, const struct string *app_name, unsigned int item_id);
__declspec(dllexport) int  parse_approot_tx				(mem_zone_ref_ptr tx);


__declspec(dllexport)  int   get_app_name					(const struct string *script, struct string *app_name);
__declspec(dllexport)  int   get_app_types				(mem_zone_ref_ptr app, mem_zone_ref_ptr types);
__declspec(dllexport)  int   get_app_scripts				(mem_zone_ref_ptr app, mem_zone_ref_ptr scripts);

__declspec(dllexport)  int	 get_type_infos				(struct string *script, char *name, unsigned int *id, unsigned int *flags);

__declspec(dllexport)  int	 get_tx_file					(mem_zone_ref_ptr tx, mem_zone_ref_ptr hash_list);
__declspec(dllexport)  int	 tx_is_app_file				(mem_zone_ref_ptr tx, struct string *appName, mem_zone_ref_ptr file);
__declspec(dllexport)  int	 get_app_type_key				(const char *appName, unsigned int type_id, const char *kname, unsigned int *ktype, unsigned int *flags);
__declspec(dllexport)  int	 get_app_type_idxs			(const char *appName, unsigned int type_id, mem_zone_ref_ptr keys);
__declspec(dllexport)  int	 load_obj_type				(const char *app_name, const char *objHash, unsigned int *type_id, btc_addr_t objAddr);
__declspec(dllexport)  int	 check_app_obj_unique			(const char *appName, unsigned int type_id, mem_zone_ref_ptr obj);









__declspec(dllexport) int    get_out_script_address(const struct string *script, struct string *pubk, btc_addr_t addr);


__declspec(dllexport) int    get_out_script_return_val(const struct string *script, struct string *data);


__declspec(dllexport) int    get_tx_output_script(const hash_t tx_hash, unsigned int idx, struct string *script, uint64_t *amount);


__declspec(dllexport) void    key_to_hash(const unsigned char *pkey, unsigned char *keyHash);


__declspec(dllexport) void   key_to_addr(const unsigned char *pkey, btc_addr_t addr);


__declspec(dllexport) void    paddr_to_key(btc_paddr_t addr, dh_key_t key);


__declspec(dllexport) int    make_script_file(mem_zone_ref_ptr file, struct string *pKey, struct string *sign, mem_zone_ref_ptr script);

__declspec(dllexport) int    make_script_layout(mem_zone_ref_ptr file, mem_zone_ref_ptr script);

__declspec(dllexport) int    make_script_module(mem_zone_ref_ptr file, mem_zone_ref_ptr script);






__declspec(dllexport) int   get_moneysupply(uint64_t *amount);


__declspec(dllexport) int  get_last_block_height();


__declspec(dllexport) int   find_blk_hash(const hash_t tx_hash, hash_t blk_hash,uint64_t *height,unsigned int *ofset,unsigned int *tx_time);


__declspec(dllexport) int   find_hash(hash_t hash);


__declspec(dllexport) int   find_index_hash(hash_t h);


__declspec(dllexport) int   load_blk_hdr(mem_zone_ref_ptr hdr, const char *blk_hash);


__declspec(dllexport) int   get_blk_height(const char *blk_hash, uint64_t *height);


__declspec(dllexport) int   get_tx_blk_height(const hash_t tx_hash, uint64_t *height, uint64_t *block_time, unsigned int *tx_time);


__declspec(dllexport) int   is_pow_block(const char *blk_hash);


__declspec(dllexport) int   store_block(mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list);


__declspec(dllexport) int   blk_load_tx_ofset(const char *blk_hash, unsigned int ofset, mem_zone_ref_ptr tx);


__declspec(dllexport) int   load_tx(mem_zone_ref_ptr tx, hash_t blk_hash, const hash_t tx_hash);


__declspec(dllexport) int   load_tx_input(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr	vin, mem_zone_ref_ptr tx_out);


__declspec(dllexport) int   load_blk_tx_input(const char *blk_hash, unsigned int tx_ofset, unsigned int vin_idx, mem_zone_ref_ptr vout);


__declspec(dllexport) int   load_tx_output_amount(const hash_t tx_hash, unsigned int idx, uint64_t *amount);


__declspec(dllexport) int   load_tx_input_vout(mem_zone_ref_const_ptr tx, unsigned int vin_idx, mem_zone_ref_ptr vout);


__declspec(dllexport) int   load_tx_addresses(btc_addr_t addr, mem_zone_ref_ptr tx_hashes);


__declspec(dllexport) int   load_obj(const char *app_name, const char *objHash, const char *objName, unsigned int opts, mem_zone_ref_ptr obj, btc_addr_t objAddr);


__declspec(dllexport) int   load_obj_childs(const char *app_name, const char *objHash, const char *KeyName, size_t first, size_t max, unsigned int opts, mem_zone_ref_ptr objs);


__declspec(dllexport) int   make_app_child_obj_tx(mem_zone_ref_ptr tx, const char *app_name, hash_t objHash, const char *keyName, unsigned int ktype,hash_t childHash);


__declspec(dllexport) int   get_app_obj_hashes(const char *app_name, mem_zone_ref_ptr hash_list);


__declspec(dllexport) int  get_app_type_last_objs_hashes(const char *app_name, unsigned int type_id, size_t first, size_t max, mem_zone_ref_ptr hash_list);


__declspec(dllexport) int   get_block_size(const char *blk_hash, size_t *size);


__declspec(dllexport) int   get_blk_tx_hash(const char* blk_hash, unsigned int idx, hash_t tx_hash);


__declspec(dllexport) int   get_blk_txs(const char* blk_hash, mem_zone_ref_ptr txs, size_t max);


__declspec(dllexport) unsigned int   get_blk_ntxs(const char* blk_hash);


__declspec(dllexport) int   load_blk_txs(const char* blk_hash, mem_zone_ref_ptr txs);


__declspec(dllexport) int   get_block_time(const char *blkHash, ctime_t *time);


__declspec(dllexport) int   store_tx_inputs(mem_zone_ref_ptr tx);


__declspec(dllexport) int   store_tx_outputs(mem_zone_ref_ptr tx);


__declspec(dllexport) int   store_tx_addresses(btc_addr_t addr, hash_t tx_hash);


__declspec(dllexport) int   remove_tx_addresses(const btc_addr_t addr, const hash_t tx_hash);


__declspec(dllexport) int   remove_tx(hash_t tx_hash);


__declspec(dllexport)  int	 load_block_indexes(mem_zone_ref_ptr hdr_list);


__declspec(dllexport)  int	 store_tx_blk_index(const hash_t tx_hash, const hash_t blk_hash,uint64_t height,size_t tx_ofset,unsigned int time);


__declspec(dllexport) int   store_block_txs(mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list);


__declspec(dllexport)  int	 clear_tx_index();


__declspec(dllexport)  int	 get_app_type_obj_hashes(const char *app_name, unsigned int type_id, size_t first, size_t max, mem_zone_ref_ptr hash_list);
__declspec(dllexport)  int	 get_app_type_nobjs(const char *app_name, unsigned int type_id);
__declspec(dllexport)  int	 get_app_file(mem_zone_ref_ptr file_tx, struct string *app_name, mem_zone_ref_ptr file);
__declspec(dllexport)  int	 get_appfile_tx(const char *app_name, hash_t fileHash, hash_t txHash);
__declspec(dllexport)  int	 has_app_file(struct string *app_name, hash_t fileHash);
__declspec(dllexport)  int	 get_app_files(struct string *app_name, size_t first, size_t num, mem_zone_ref_ptr files);
__declspec(dllexport)  int	 get_app_missing_files(struct string *app_name, mem_zone_ref_ptr pending, mem_zone_ref_ptr files);





typedef int  get_blk_staking_infos_func	(mem_zone_ref_ptr blk, const char *blk_hash, mem_zone_ref_ptr infos);
typedef int	 store_tx_staking_func		(mem_zone_ref_ptr tx, hash_t tx_hash, btc_addr_t stake_addr, uint64_t	stake_in);
typedef int	 get_tx_pos_hash_data_func	(mem_zone_ref_ptr hdr, const hash_t txHash, unsigned int OutIdx, struct string *hash_data, uint64_t *amount, hash_t out_diff);
typedef int	 get_target_spacing_func		(unsigned int *target);
typedef int	 get_stake_reward_func		(uint64_t height, uint64_t *reward);
typedef int	 get_last_stake_modifier_func	(mem_zone_ref_ptr pindex, hash_t nStakeModifier, unsigned int *nModifierTime);
typedef int	 compute_tx_pos_func			(mem_zone_ref_ptr tx, hash_t StakeModifier, unsigned int txTime, hash_t pos_hash, uint64_t *weight);
typedef int	 create_pos_block_func		(hash_t pHash, mem_zone_ref_ptr tx, mem_zone_ref_ptr newBlock);
typedef int	 check_tx_pos_func			(mem_zone_ref_ptr blk, mem_zone_ref_ptr tx);
typedef int	 get_min_stake_depth_func		(unsigned int *depth);
typedef unsigned int 	get_current_pos_difficulty_func();

typedef get_blk_staking_infos_func		*get_blk_staking_infos_func_ptr;
typedef store_tx_staking_func			*store_tx_staking_func_ptr;
typedef get_tx_pos_hash_data_func		*get_tx_pos_hash_data_func_ptr;
typedef get_target_spacing_func			*get_target_spacing_func_ptr;
typedef get_stake_reward_func			*get_stake_reward_func_ptr;
typedef get_last_stake_modifier_func	*get_last_stake_modifier_func_ptr;
typedef compute_tx_pos_func				*compute_tx_pos_func_ptr;
typedef create_pos_block_func			*create_pos_block_func_ptr;
typedef check_tx_pos_func				*check_tx_pos_func_ptr;
typedef get_min_stake_depth_func		*get_min_stake_depth_func_ptr;
typedef get_current_pos_difficulty_func	*get_current_pos_difficulty_func_ptr;
#line 19 "block.c"
#line 1 "C:\\bitstream\\serv\\libcon\\include\\bin_tree.h"

typedef unsigned int tree_entry[9];

struct bin_tree {
	tree_entry			data;
	struct bin_tree		* right, *left;
};

typedef struct bin_tree node;

__declspec(dllimport)		int				 bt_insert (node ** tree, tree_entry val);
__declspec(dllimport)		void			 bt_deltree(node * tree);
__declspec(dllimport)		node *			 bt_search (node * tree, tree_entry val);

#line 20 "block.c"

__declspec(dllimport) size_t				compute_payload_size(mem_zone_ref_ptr payload_node);
__declspec(dllimport) char*				write_node			(mem_zone_ref_const_ptr key, unsigned char *payload);
__declspec(dllimport) size_t				get_node_size		(mem_zone_ref_ptr key);
__declspec(dllimport) void				serialize_children	(mem_zone_ref_ptr node, unsigned char *payload);
__declspec(dllimport) const char*		read_node			(mem_zone_ref_ptr key, const char *payload, size_t len);
__declspec(dllimport) void				unserialize_children(mem_zone_ref_ptr obj, const_mem_ptr payload,size_t len);

extern int				store_tx_vout(const char *txh,mem_zone_ref_ptr txout_list,unsigned int oidx, btc_addr_t out_addr);




extern int				check_sign(const struct string *sign, const struct string *pubK, const hash_t txh);

extern int				check_txout_key(mem_zone_ref_ptr output, unsigned char *pkey,btc_addr_t addr);

extern int				scrypt_blockhash(const void* input, hash_t hash);

extern	int				add_script_var	(mem_zone_ref_ptr script_node, const struct string *val);

extern  int				add_script_uivar(mem_zone_ref_ptr script_node,uint64_t val);

extern  int				get_script_file(struct string *script, mem_zone_ref_ptr file);


extern int				b58tobin(void *bin, size_t *binszp, const char *b58, size_t b58sz);

extern void				keyrh_to_addr(unsigned char *pkeyh, btc_addr_t addr);

extern struct string	get_next_script_var(const struct string *script,size_t *offset);

extern int add_script_opcode(mem_zone_ref_ptr script_node, unsigned char opcode);

extern int add_script_push_data(mem_zone_ref_ptr script_node, const_mem_ptr data, size_t size);

extern int get_script_data(const struct string *script, size_t *offset, struct string *data);

extern int get_script_layout(struct string *script, mem_zone_ref_ptr file);
extern int get_script_module(struct string *script, mem_zone_ref_ptr file);
extern int find_index_str(const char *app_name, const char *typeStr, const char *keyname, const struct string *val, hash_t hash);




hash_t					null_hash			= { 0xCD };
hash_t					app_root_hash		= { 0xCD };
btc_addr_t				root_app_addr		= { 0xCD };
uint64_t				app_fee				=  0xFFFFFFFF;

mem_zone_ref			apps				= {(void *)0xDEADBEEFLL};
mem_zone_ref			blkobjs				= { (void *)0xDEADBEEFLL };

const char				*null_hash_str		= "0000000000000000000000000000000000000000000000000000000000000000";
unsigned char			pubKeyPrefix		= 0xFF;
static const uint64_t	one_coin			= 100000000ULL;
tpo_mod_file			sign_tpo_mod		= { 0xCD };

unsigned int			has_root_app		= 0xFFFFFFFF;
unsigned int			block_version		= 7;
unsigned int			diff_limit			= 0x1E0FFFFF;
unsigned int			TargetTimespan		= 960;
unsigned int			TargetSpacing		= 64;
unsigned int			MaxTargetSpacing	= 640;
unsigned int			reward_halving		= 0xFFFFFFFF;

uint64_t				last_pow_block		= 0xFFFFFFFF;
uint64_t				pow_reward			= 100000*100000000ULL;

node					*blk_root = (void *)0xDEADBEEFLL;








crypto_extract_key_func_ptr crypto_extract_key = (void *)0xDEADBEEFLL;
crypto_sign_open_func_ptr	crypto_sign_open   = (void *)0xDEADBEEFLL;


crypto_sign_func_ptr		crypto_sign		   = (void *)0xDEADBEEFLL;
#line 104 "block.c"

#line 106 "block.c"



int load_sign_module(mem_zone_ref_ptr mod_def, tpo_mod_file *tpo_mod)
{
	char			file[256];
	char			name[64];
	int				ret=1;

	strcpy_cs							(name, 64, tree_mamanger_get_node_name(mod_def));
	tree_manager_get_child_value_str	(mod_def, calc_crc32_c("file"), file, 256, 0);
	ret=load_module(file, name, tpo_mod);
	if(ret)
	{


		crypto_extract_key = (crypto_extract_key_func_ptr)get_tpo_mod_exp_addr_name(tpo_mod, "crypto_extract_key", 0);
		crypto_sign_open = (crypto_sign_open_func_ptr)get_tpo_mod_exp_addr_name(tpo_mod, "crypto_sign_open", 0);

		crypto_sign = (crypto_sign_func_ptr)get_tpo_mod_exp_addr_name(tpo_mod, "crypto_sign", 0);
#line 127 "block.c"
#line 128 "block.c"
		tree_manager_set_child_value_ptr(mod_def, "mod_ptr", tpo_mod);
	}
	return ret;
}


__declspec(dllexport) int  init_blocks(mem_zone_ref_ptr node_config)
{
	hash_t				msgh;
	dh_key_t			privkey;
	dh_key_t			pubkey;
	mem_zone_ref		mining_conf = { (void *)0x00000000L }, mod_def = { (void *)0x00000000L };
	struct string		sign = { (void *)0x00000000L };
	struct string		msg = { (void *)0x00000000L };
	struct string		pkstr,str = { (void *)0x00000000L }, strh = { (void *)0x00000000L };
	int					i;

	memset_c						(null_hash, 0, 32);
	memset_c						(app_root_hash, 0, 32);
	memset_c						(root_app_addr, 0, sizeof(btc_addr_t));

	blk_root = (void *)0x00000000L;

	apps.zone = (void *)0x00000000L;
	blkobjs.zone = (void *)0x00000000L;
	has_root_app = 0;
	app_fee = 0;
	tree_manager_create_node("apps", 0x0B004000, &apps);
	
	tree_manager_get_child_value_i32(node_config, calc_crc32_c("pubKeyVersion"), &i);
	pubKeyPrefix = i;

	if (!tree_manager_find_child_node(node_config, calc_crc32_c("sign_mod"), 0x08000008, &mod_def))
	{
		log_output("no signature module\n");
		return 0;
	}

	load_sign_module(&mod_def, &sign_tpo_mod);
	release_zone_ref(&mod_def);
	

	if (!tree_manager_get_child_value_i32(node_config, calc_crc32_c("block_version"), &block_version))
		block_version = 7;


	last_pow_block = 0;
	reward_halving = 0;


	if (tree_manager_find_child_node(node_config, calc_crc32_c("mining"), 0xFFFFFFFF, &mining_conf))
	{
		tree_manager_get_child_value_i32(&mining_conf, calc_crc32_c("limit"), &diff_limit);
		tree_manager_get_child_value_i32(&mining_conf, calc_crc32_c("targettimespan"), &TargetTimespan);
		tree_manager_get_child_value_i32(&mining_conf, calc_crc32_c("targetspacing"), &TargetSpacing);
		tree_manager_get_child_value_i32(&mining_conf, calc_crc32_c("maxtargetspacing"), &MaxTargetSpacing);
		tree_manager_get_child_value_i64(&mining_conf, calc_crc32_c("reward"), &pow_reward);


		tree_manager_get_child_value_i64(&mining_conf, calc_crc32_c("last_pow_block"), &last_pow_block);
		tree_manager_get_child_value_i32(&mining_conf, calc_crc32_c("reward_halving"), &reward_halving);
			
		release_zone_ref				(&mining_conf);
	}

	blk_load_app_root();

	blk_load_apps(&apps);


	for (i = 0; i < 64; i++)
		privkey[i] = 0;

	crypto_extract_key	(pubkey, privkey);
	make_string			(&str, "abcdef");
	mbedtls_sha256		(str.str, str.len, msgh,0);

	strh.str = msgh;
	strh.len = 32;

	pkstr.str	= pubkey;
	pkstr.len	= 64;
	
	sign = crypto_sign		(&strh, privkey);
	i = crypto_sign_open    (&sign, &strh, &pkstr);

	if (i==1)
	{
		mem_zone_ref log = { (void *)0x00000000L };
		tree_manager_create_node("log", 0x0A000010, &log);
		tree_manager_set_child_value_str(&log, "msg", msg.str);
		log_message("crypto sign ok '%msg%'", &log);
		release_zone_ref(&log);
	}
	else
		log_message("crypto sign error", (void *)0x00000000L);
#line 225 "block.c"
	return 1;
}
__declspec(dllexport) int  block_pow(uint64_t height)
{
	if (last_pow_block == 0)return 1;
	if (height<=last_pow_block)return 1;

	return 0;
}

__declspec(dllexport) int  extract_key(dh_key_t priv,dh_key_t pub)
{
	return crypto_extract_key(pub, priv);
}



__declspec(dllexport) int  blk_find_last_pow_block(mem_zone_ref_ptr pindex, unsigned int *block_time)
{
	char			chash[65];
	int				ret = 0;

	if (last_pow_block > 0)
	{
		hash_t		lbp;
		uint64_t    bh;
		unsigned int n;

		tree_manager_get_child_value_i64(pindex, calc_crc32_c("height"), &bh);

		if ((bh > 201) && (bh<110500))
			bh = 200;

		if (bh > last_pow_block)
			bh = last_pow_block;

		get_hash_idx("blk_indexes", bh-1, lbp);
		n = 0;
		while (n < 32)
		{
			chash[n * 2 + 0] = hex_chars[lbp[n] >> 0x04];
			chash[n * 2 + 1] = hex_chars[lbp[n] & 0x0F];
			n++;
		}
		chash[64] = 0;

		load_blk_hdr(pindex, chash);
	}


	tree_manager_get_child_value_str(pindex, calc_crc32_c("blkHash"), chash, 65, 16);
	while (!is_pow_block(chash))
	{
		tree_manager_get_child_value_str(pindex, calc_crc32_c("prev"), chash, 65, 16);
		if (!load_blk_hdr(pindex, chash))
			return 0;
	}
	if (is_pow_block(chash))
	{
		tree_manager_get_child_value_i32(pindex, calc_crc32_c("time"), block_time);
		return 1;
	}
	return 0;
}

int add_app_tx(mem_zone_ref_ptr new_app, const char *app_name)
{
	mem_zone_ref txout_list = { (void *)0x00000000L };
	tree_manager_set_child_value_str(new_app, "appName", app_name);

	if (tree_manager_find_child_node(new_app, calc_crc32_c("txsout"), 0x0B080000, &txout_list))
	{
		mem_zone_ref		my_list = { (void *)0x00000000L };
		mem_zone_ref_ptr	out = (void *)0x00000000L;
		for (tree_manager_get_first_child(&txout_list, &my_list, &out); ((out != (void *)0x00000000) && (out->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &out))
		{
			btc_addr_t	appAddr;
			struct string script = { 0 }, val = { 0 }, pubk = { 0 };

			tree_manager_get_child_value_istr(out, calc_crc32_c("script"), &script, 0);

			if (get_out_script_return_val(&script, &val))
			{
				if (val.len == 1)
				{
					unsigned char app_item=*((unsigned char *)(val.str));

					tree_manager_set_child_value_i32(out, "app_item", app_item);

					if (!tree_manager_find_child_node(new_app, calc_crc32_c("appAddr"), 0x0B009000, (void *)0x00000000L))
					{
						if (get_out_script_address(&script, &pubk, appAddr))
						{
							tree_manager_set_child_value_btcaddr(new_app, "appAddr", appAddr);
							free_string(&pubk);
						}
					}
				}
				free_string(&val);
			}
			free_string(&script);
		}
	}
	release_zone_ref(&txout_list);
	tree_manager_node_add_child(&apps, new_app);

	return 1;
}

__declspec(dllexport) int  get_block_version(unsigned int *v)
{
	*v = block_version;
	return 1;
}
__declspec(dllexport) int  get_apps(mem_zone_ref_ptr Apps)
{
	if (!has_root_app)return 0;
	copy_zone_ref(Apps, &apps);
	return 1;
}

__declspec(dllexport) int  set_root_app(mem_zone_ref_ptr tx)
{
	mem_zone_ref vout={(void *)0x00000000L};
	if(tx==(void *)0x00000000L)
	{
		has_root_app =	 0;
		app_fee      =  0;
		memset_c(app_root_hash,0,sizeof(hash_t));
		return 1;
	}
	if(has_root_app==1)return 0;
	compute_tx_hash		(tx,app_root_hash);

	if ( get_tx_output(tx, 0, &vout))
	{
		struct string	script={0},var={0};
		size_t			offset=0;
		tree_manager_get_child_value_istr	(&vout, calc_crc32_c("script"), &script,0);
		tree_manager_get_child_value_i64	(&vout, calc_crc32_c("value"), &app_fee);
		
		app_fee &= 0xFFFFFFFF;
		var = get_next_script_var			(&script,&offset);
		free_string							(&script);
		keyrh_to_addr						((unsigned char *)(var.str), root_app_addr);
		free_string							(&var);
		release_zone_ref					(&vout);
	}
	has_root_app =	 1;

	return 1;
}
__declspec(dllexport) int  get_root_app(mem_zone_ref_ptr rootAppHash)
{
	if(has_root_app==0)return 0;

	if(rootAppHash!=(void *)0x00000000L)
		tree_manager_write_node_hash(rootAppHash,0,app_root_hash);

	return 1;
}

__declspec(dllexport) int  get_root_app_addr(mem_zone_ref_ptr rootAppAddr)
{
	if(has_root_app==0)return 0;
	tree_manager_write_node_btcaddr(rootAppAddr,0,root_app_addr);
	return 1;
}

__declspec(dllexport) int  get_root_app_fee(mem_zone_ref_ptr rootAppFees)
{
	if(has_root_app==0)return 0;

	tree_manager_write_node_qword(rootAppFees, 0, app_fee);
	return 1;
}


__declspec(dllexport) int  get_blockreward(uint64_t block, uint64_t *block_reward)
{
	uint64_t nhavles;
	

	if ((reward_halving == 0) || (block<reward_halving))
	{
		*block_reward = pow_reward;
		return 1;
	}

	nhavles			= muldiv64	(block, 1, reward_halving);
	*block_reward	= shr64		(pow_reward, nhavles);
	
	return 1;
	
}

__declspec(dllexport) int  get_pow_reward(mem_zone_ref_ptr height, mem_zone_ref_ptr Reward)
{
	uint64_t	 reward;
	unsigned int nHeight;
	
	tree_mamanger_get_node_dword	(height, 0, &nHeight);
	get_blockreward					(nHeight, &reward);
	tree_manager_write_node_qword	(Reward, 0, reward);
	return 1;
}


__declspec(dllexport) int  tx_add_input(mem_zone_ref_ptr tx, const hash_t tx_hash, unsigned int index, const struct string *script)
{
	mem_zone_ref txin_list			= { (void *)0x00000000L },txin = { (void *)0x00000000L }, out_point = { (void *)0x00000000L };

	if (!tree_manager_create_node("txin", 0x0B020000, &txin))return 0;
	
	tree_manager_set_child_value_hash	(&txin, "txid", tx_hash);
	tree_manager_set_child_value_i32	(&txin, "idx", index);

	if (script!=(void *)0x00000000L)
		tree_manager_set_child_value_vstr	(&txin, "script"	, script);

	tree_manager_set_child_value_i32	(&txin, "sequence"	, 0xFFFFFFFF);
		
	tree_manager_find_child_node		(tx, calc_crc32_c("txsin"), 0x0B010000, &txin_list);
	tree_manager_node_add_child			(&txin_list			, &txin);
	release_zone_ref					(&txin);
	release_zone_ref					(&txin_list);

	
	return 1;
}

__declspec(dllexport) int  tx_add_output(mem_zone_ref_ptr tx, uint64_t value, const struct string *script)
{
	btc_addr_t		dstaddr;
	mem_zone_ref	txout_list = { (void *)0x00000000L },txout = { (void *)0x00000000L };

	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsout"), 0x0B080000, &txout_list))return 0;

	tree_manager_create_node			("txout", 0x0B100000, &txout);
	tree_manager_set_child_value_i64	(&txout, "value", value);
	tree_manager_set_child_value_vstr	(&txout, "script", script);

	if (get_out_script_address(script, (void *)0x00000000L, dstaddr))
	{
		tree_manager_set_child_value_btcaddr(&txout, "dstaddr", dstaddr);
	}


	tree_manager_node_add_child			(&txout_list, &txout);
	release_zone_ref					(&txout);
	release_zone_ref					(&txout_list);
	return 1;
}

__declspec(dllexport) int  new_transaction(mem_zone_ref_ptr tx, ctime_t time)
{
	if (tx->zone==(void *)0x00000000L)
		tree_manager_create_node		("transaction"	, 0x0B008000, tx);

	tree_manager_set_child_value_i32(tx, "version"	, 1);
	tree_manager_set_child_value_i32(tx, "time"		, time);
	tree_manager_add_child_node		(tx, "txsin"	, 0x0B010000 , (void *)0x00000000L);
	tree_manager_add_child_node		(tx, "txsout"	, 0x0B080000, (void *)0x00000000L);
	tree_manager_set_child_value_i32(tx, "locktime"	, 0);


	tree_manager_set_child_value_i32(tx, "submitted", 0);
	return 1;
}

__declspec(dllexport) int  get_app_name(const struct string *script, struct string *app_name)
{
	struct string var = { 0 };
	size_t offset = 0;
	int		ret=0;
	var = get_next_script_var(script, &offset);

	if ((var.len>0) && (var.len<script->len))
	{
		make_string(app_name, var.str);
		ret = 1;
	}

	free_string(&var);
	return ret;
}

__declspec(dllexport) int  parse_approot_tx(mem_zone_ref_ptr tx)
{
	int ret;
	mem_zone_ref txout_list = { (void *)0x00000000L },vout={(void *)0x00000000L};

	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsout"), 0x0B080000, &txout_list))return 0;
	ret=tree_manager_get_child_at(&txout_list, 0, &vout);
	if(ret)
	{
	    struct string oscript = {0},var = {0};
	    size_t offset=0;
	    
		tree_manager_get_child_value_istr	(&vout,calc_crc32_c("script"),&oscript,0);
		var = get_next_script_var			(&oscript,&offset);
		free_string							(&oscript);
		
		if(var.len>0)
		{
			btc_addr_t	addr;
			keyrh_to_addr						 	(var.str, addr);
			tree_manager_set_child_value_btcaddr	(tx,"dstaddr",addr);
		}
		
		free_string		(&var);
		release_zone_ref(&vout);
	}

	release_zone_ref(&txout_list);
	
	return ret;
}

__declspec(dllexport) int  make_approot_tx(mem_zone_ref_ptr tx, ctime_t time,btc_addr_t addr)
{
	hash_t			txH;
	unsigned char	addrBin[26];
	mem_zone_ref	script			= { (void *)0x00000000L };
	struct string	sscript,var		= { 0 }, strKey  = { (void *)0x00000000L };
	size_t			sz;
	int				ret;

	new_transaction			(tx,time);

	ret=tree_manager_create_node("iapproot",0x0B200000,&script);
	if(ret)
	{
		make_string				(&var,"AppRoot");
		add_script_var			(&script,&var);
		free_string				(&var);
	

		serialize_script		(&script,&sscript);
		release_zone_ref		(&script);
		
		tx_add_input			(tx,null_hash,0xFFFFFFFF,&sscript);
		free_string				(&sscript);
	}

	if(ret)ret=tree_manager_create_node("oapproot",0x0B200000,&script);
	if(ret)
	{
		sz					= 25;
		b58tobin			(addrBin, &sz, addr, sizeof(btc_addr_t));
		make_string_l		(&strKey, (char *)(addrBin + 1), 20);

		add_script_var		(&script,&strKey);
		free_string			(&strKey);

		serialize_script	(&script,&sscript);
		release_zone_ref	(&script);

		tx_add_output		(tx,1000000ULL,&sscript);
		free_string			(&sscript);
	}
	
	tree_manager_set_child_value_i32(tx,"is_app_root",1);
	
	if(ret)
	{
		compute_tx_hash						(tx,txH);
		tree_manager_set_child_value_hash	(tx,"txid",txH);
	}
	return ret;
}

__declspec(dllexport) int  make_app_tx(mem_zone_ref_ptr tx,const char *app_name,btc_addr_t appAddr)
{
	hash_t			txH;
	mem_zone_ref	script			= { (void *)0x00000000L };
	struct string	sscript,var		= { 0 }, strKey  = { (void *)0x00000000L };
	ctime_t			time;
	int				ret;

	if(!has_root_app)return 0;


	time	=	get_time_c();
	new_transaction			(tx,time);

	ret=tree_manager_create_node("appinput",0x0B200000,&script);
	if(ret)
	{
		mem_zone_ref vin = { (void *)0x00000000L };
		make_string				(&var,app_name);
		add_script_var			(&script,&var);
		free_string				(&var);

		serialize_script		(&script,&sscript);
		release_zone_ref		(&script);
		
		tx_add_input			(tx,app_root_hash,0,&sscript);

		free_string				(&sscript);

		if (get_tx_input(tx, 0, &vin))
		{
			tree_manager_set_child_value_bool	(&vin, "isApp", 1);
			tree_manager_set_child_value_str	(&vin,"appName",app_name);
			release_zone_ref(&vin);
		}
	}

	if(ret)ret=tree_manager_create_node("oapproot",0x0B200000,&script);
	if (ret)
	{
		
		create_p2sh_script_byte(appAddr, &script, 1);
		serialize_script(&script, &sscript);
		release_zone_ref(&script);
		tx_add_output(tx, 0, &sscript);
		free_string(&sscript);
	}
	if (ret)ret = tree_manager_create_node("oapproot", 0x0B200000, &script);
	if (ret)
	{
		
		create_p2sh_script_byte(appAddr, &script, 2);
		serialize_script(&script, &sscript);
		release_zone_ref(&script);
		tx_add_output(tx, 0, &sscript);
		free_string(&sscript);
	}

	if (ret)ret = tree_manager_create_node("oapproot", 0x0B200000, &script);
	if (ret)
	{
		
		create_p2sh_script_byte(appAddr, &script, 3);
		serialize_script(&script, &sscript);
		release_zone_ref(&script);
		tx_add_output(tx, 0, &sscript);
		free_string(&sscript);
	}
	if (ret)ret = tree_manager_create_node("oapproot", 0x0B200000, &script);
	if (ret)
	{
		
		create_p2sh_script_byte(appAddr, &script, 4);
		serialize_script(&script, &sscript);
		release_zone_ref(&script);
		tx_add_output(tx, 0, &sscript);
		free_string(&sscript);
	}
	if (ret)ret = tree_manager_create_node("oapproot", 0x0B200000, &script);
	if (ret)
	{
		
		create_p2sh_script_byte	(appAddr, &script,5);
		serialize_script		(&script,&sscript);
		release_zone_ref		(&script);
		tx_add_output			(tx,0,&sscript);
		free_string				(&sscript);
	}

	if(ret)
	{
		compute_tx_hash						(tx,txH);
		tree_manager_set_child_value_hash	(tx,"txid",txH);
	}
	return ret;
}



__declspec(dllexport) int  make_app_item_tx(mem_zone_ref_ptr tx, const struct string *app_name, unsigned int item_id)
{
	hash_t			txH,appH;
	btc_addr_t		appAddr;
	mem_zone_ref	script = { (void *)0x00000000L }, my_list = { (void *)0x00000000L }, txout_list = { (void *)0x00000000L }, app = { (void *)0x00000000L };
	mem_zone_ref_ptr out = (void *)0x00000000L;
	struct string	var = { 0 }, strKey = { (void *)0x00000000L };
	ctime_t			time;
	unsigned int	oidx;
	int				ret;
	int				item_oidx=-1;

	if (!has_root_app)return 0;

	if (!tree_node_find_child_by_name(&apps, app_name->str, &app))return 0;

	if (!tree_manager_find_child_node(&app, calc_crc32_c("txsout"), 0x0B080000, &txout_list))return 0;
	for (oidx = 0, tree_manager_get_first_child(&txout_list, &my_list, &out); ((out != (void *)0x00000000) && (out->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &out), oidx++)
	{
		struct string script_str = { 0 }, val = { 0 };
		tree_manager_get_child_value_istr(out, calc_crc32_c("script"), &script_str,0);

		if (get_out_script_return_val(&script_str, &val))
		{
			if ((val.len == 1) && ((*((unsigned char *)(val.str))) == item_id))
			{
				item_oidx = oidx;
			}
			free_string(&val);
		}
		free_string(&script_str);
	}
	release_zone_ref(&txout_list);

	if (item_oidx < 0)
	{
		release_zone_ref(&app);
		return 0;
	}

	tree_manager_get_child_value_hash(&app, calc_crc32_c("txid"), appH);
	tree_manager_get_child_value_btcaddr(&app, calc_crc32_c("appAddr"), appAddr);
	release_zone_ref(&app);
	

	time = get_time_c();
	new_transaction(tx, time);

	ret = tree_manager_create_node("appinput", 0x0B200000, &script);
	if (ret)
	{
		mem_zone_ref vin = { (void *)0x00000000L };
		struct string null_str = { 0 };

		

		tx_add_input(tx, appH, item_oidx, &null_str);
		if (get_tx_input(tx, 0, &vin))
		{
			if (item_id == 1)tree_manager_set_child_value_bool	(&vin, "isAppType", 1);
			if (item_id == 2)tree_manager_set_child_value_bool	(&vin, "isAppObj", 1);
			if (item_id == 3)tree_manager_set_child_value_bool	(&vin, "isAppFile", 1);
			if (item_id == 4)tree_manager_set_child_value_bool	(&vin, "isAppLayout", 1);
			if (item_id == 5)tree_manager_set_child_value_bool	(&vin, "isAppModule", 1);

			tree_manager_allocate_child_data(&vin, "script", 256);

			
			tree_manager_set_child_value_vstr(&vin, "srcapp", app_name);
			
			release_zone_ref(&vin);
		}
	}
	tree_manager_set_child_value_i32(tx, "app_item", item_id);
	if (ret)
	{
		compute_tx_hash(tx, txH);
		tree_manager_set_child_value_hash(tx, "txid", txH);
	}
	return ret;
}

__declspec(dllexport) int  make_app_child_obj_tx(mem_zone_ref_ptr tx, const char *app_name, hash_t objHash, const char *keyName, unsigned int ktype, hash_t childHash)
{
	char				chash[65];
	btc_addr_t			objAddr;
	mem_zone_ref		vin = { (void *)0x00000000L }, script = { (void *)0x00000000L }, my_list = { (void *)0x00000000L }, txout_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	out = (void *)0x00000000L;
	struct string		sscript = { 0 }, strKey = { 0 }, null_str = { 0 };
	ctime_t				time;
	unsigned int		n, keytype, objType, flags;
	int					ret;
	int					item_oidx = -1;

	if (!has_root_app)return 0;

	if (!tree_node_find_child_by_name(&apps, app_name, (void *)0x00000000L))return 0;

	n = 0;
	while (n < 32)
	{
		chash[n * 2 + 0] = hex_chars[objHash[n] >> 0x04];
		chash[n * 2 + 1] = hex_chars[objHash[n] & 0x0F];
		n++;
	}
	chash[64] = 0;

	ret = load_obj_type(app_name, chash, &objType, objAddr);
	if (ret)ret = get_app_type_key(app_name, objType, keyName, &keytype,&flags);
	if (ret)ret = ((keytype == 0x09000001) || (keytype == 0x09000002)) ? 1 : 0;
	if (!ret)return 0;
	
	time = get_time_c	();
	new_transaction		(tx, time);

	tree_manager_create_node("script", 0x0B200000, &script);

	add_script_push_data	(&script,	keyName, strlen_c(keyName));
	add_script_push_data	(&script,	childHash, 32);
	add_script_opcode		(&script,	0x93);
	serialize_script		(&script,	&sscript);

	tx_add_input			(tx, objHash, 0, &null_str);
	if (get_tx_input(tx, 0, &vin))
	{
		tree_manager_set_child_value_str	(&vin, "srcapp", app_name);

		if (ktype==0x09000001)
			tree_manager_set_child_value_btcaddr(&vin, "srcaddr", objAddr);

		tree_manager_set_child_value_bool		(&vin, "addChild", 1);
		tree_manager_set_child_value_i64		(&vin, "amount", 0);
		release_zone_ref						(&vin);
	}
	
	
	tx_add_output			(tx, 0, &sscript);



	release_zone_ref		(&script);
	free_string				(&sscript);
	

	return ret;

}

__declspec(dllexport) int  compute_tx_hash(mem_zone_ref_ptr tx, hash_t hash)
{
	hash_t		  tx_hash;
	size_t		  length;
	unsigned char *buffer;

	length = get_node_size(tx);
	buffer = (unsigned char *)malloc_c(length);
	write_node		(tx, buffer);
	mbedtls_sha256	(buffer, length, tx_hash, 0);
	mbedtls_sha256	(tx_hash, 32, hash, 0);
	free_c			(buffer);
	tree_manager_set_child_value_i32(tx, "size", length);
	return 1;
}


__declspec(dllexport) int  compute_block_pow(mem_zone_ref_ptr block, hash_t hash)
{
	size_t		  length;
	unsigned char *buffer;

	length = get_node_size(block);
	buffer = malloc_c(length);
	write_node(block, buffer);

	scrypt_blockhash(buffer, hash);
	free_c(buffer);
	return 1;
}

__declspec(dllexport) int  compute_block_hash(mem_zone_ref_ptr block, hash_t hash)
{
	unsigned int			checksum1[8];
	size_t					length;
	unsigned char			*buffer;

	length = get_node_size(block);
	buffer = malloc_c(length);
	write_node	(block, buffer);

	mbedtls_sha256(buffer, 80, (unsigned char*)checksum1, 0);
	mbedtls_sha256((unsigned char*)checksum1, 32, hash, 0);
	free_c(buffer);

	return 1;
}

__declspec(dllexport) int  set_block_hash(mem_zone_ref_ptr block)
{
	hash_t hash;
	compute_block_hash					(block, hash);
	tree_manager_set_child_value_bhash	(block, "blkHash", hash);
	return 1;
}

__declspec(dllexport) int  get_hash_list_from_tx(mem_zone_ref_ptr txs, mem_zone_ref_ptr hashes)
{
	mem_zone_ref		my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	tx =  (void *)0x00000000L ;
	int					n;

	for (n = 0, tree_manager_get_first_child(txs, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); n++, tree_manager_get_next_child(&my_list, &tx))
	{
		hash_t h;
		compute_tx_hash						(tx, h);
		tree_manager_set_child_value_hash	(tx, "txid", h);
		tree_manager_write_node_hash		(hashes, n*sizeof(hash_t), h);
	}

	return n;
}

unsigned int compute_merkle_round(mem_zone_ref_ptr hashes,int cnt)
{
	int						i, newN;
	hash_t					tx_hash, tmp;
	mbedtls_sha256_context	ctx;

	newN = 0;
	for (i = 0; i < cnt; i += 2)
	{
		hash_t branch;
		mbedtls_sha256_init			(&ctx);
		mbedtls_sha256_starts		(&ctx, 0);

		tree_manager_get_node_hash	(hashes, i*sizeof(hash_t), tx_hash);
		mbedtls_sha256_update		(&ctx, tx_hash, sizeof(hash_t));

		if ((i + 1)<cnt)
			tree_manager_get_node_hash(hashes, (i + 1)*sizeof(hash_t), tx_hash);

		mbedtls_sha256_update	(&ctx, tx_hash, sizeof(hash_t));
		mbedtls_sha256_finish	(&ctx, tmp);
		mbedtls_sha256_free		(&ctx);

		mbedtls_sha256			(tmp, 32, branch, 0);

		tree_manager_write_node_hash(hashes, (newN++)*sizeof(hash_t), branch);
	}

	return newN;
}
__declspec(dllexport) int  build_merkel_tree(mem_zone_ref_ptr txs, hash_t merkleRoot)
{
	hash_t					tx_hash, tmp;
	mbedtls_sha256_context	ctx;
	mem_zone_ref			hashes = { (void *)0x00000000L };
	int						n, newLen;

	if (!tree_manager_create_node("hashes", 0x0B007000, &hashes))return 0;

	n	=	get_hash_list_from_tx(txs, &hashes);

	if (n == 0)
	{
		release_zone_ref(&hashes);
		return 0;
	}
	
	if (n == 1)
	{
		tree_manager_get_node_hash	(&hashes, 0, merkleRoot);
		release_zone_ref(&hashes);
		return 1;
	}
	if (n == 2)
	{
		mbedtls_sha256_init			(&ctx);
		mbedtls_sha256_starts		(&ctx, 0);
		

		tree_manager_get_node_hash	(&hashes, 0, tx_hash);
		mbedtls_sha256_update		(&ctx, tx_hash, sizeof(hash_t));

		tree_manager_get_node_hash	(&hashes, sizeof(hash_t), tx_hash);
		mbedtls_sha256_update		(&ctx, tx_hash, sizeof(hash_t));

		mbedtls_sha256_finish		(&ctx, tmp);
		mbedtls_sha256_free			(&ctx);
		mbedtls_sha256				(tmp, 32, merkleRoot, 0);
		release_zone_ref(&hashes);
		return 1;
	}


	while ((newLen=compute_merkle_round(&hashes, n))>1)
	{
		n = newLen;
	}
	
	tree_manager_get_node_hash	(&hashes, 0, merkleRoot);


	release_zone_ref			(&hashes);
	
	

	return 1;
}


__declspec(dllexport) unsigned int  SetCompact(unsigned int bits, hash_t out)
{
	unsigned int  nSize = bits >> 24;
	size_t		  ofset;

	memset_c(out, 0, 32);

	if (nSize < 32)
		ofset = 32 - nSize;
	else
		return 0;

	if (nSize >= 1) out[0 + ofset] = (bits >> 16) & 0xff;
	if (nSize >= 2) out[1 + ofset] = (bits >> 8) & 0xff;
	if (nSize >= 3) out[2 + ofset] = (bits >> 0) & 0xff;

	return 1;
}

__declspec(dllexport) int  cmp_hashle(hash_t hash1, hash_t hash2)
{
	int n = 32;
	while (n--)
	{
		if (hash1[n] < hash2[n])
			return 1;
		if (hash1[n] > hash2[n])
			return -1;
	}
	return 1;
}



__declspec(dllexport) void  mul_compact(unsigned int nBits, uint64_t op, hash_t hash)
{
	char dd[16];
	mem_zone_ref log = { (void *)0x00000000L };
	unsigned int size,d;
	unsigned char *pdata;
	struct big64 bop;
	struct big128 data;
	int			n;
	size	= (nBits >> 24)-3;
	d		= (nBits & 0xFFFFFF);

	uitoa_s(nBits, dd, 16, 16);

	bop.m.v64 = op;
	big128_mul(d, bop, &data);

	memset_c(hash, 0, 32);

	pdata = (unsigned char *)data.v;

	n = 0;
	while ((n<16) && ((size+n)<32))
	{
		hash[size + n] = pdata[n];
		n++;
	}
}

unsigned int scale_compact(unsigned int nBits, uint64_t mop, uint64_t dop)
{
	unsigned int size;
	unsigned int ret;
	unsigned int bdata;
	uint64_t	data;
	size = (nBits >> 24);
	data = muldiv64(nBits & 0xFFFFFF, mop, dop);
	
	while (data&(~0xFFFFFFUL))
	{
		data=shr64(data, 8);
		size++;
	}
	bdata = data & 0x00FFFFFF;
	ret = ((size & 0xFF) << 24) | bdata;

	return ret;
}


__declspec(dllexport) unsigned int  calc_new_target(unsigned int nActualSpacing, unsigned int TargetSpacing, unsigned int nTargetTimespan,unsigned int pBits)
{
	unsigned int		nInterval;
	uint64_t			mulop , dividend;
	nInterval = nTargetTimespan / TargetSpacing;
	mulop  = ((nInterval - 1) * TargetSpacing + nActualSpacing + nActualSpacing);
	dividend  = ((nInterval + 1) * TargetSpacing);
	return scale_compact(pBits, mulop, dividend);
}

__declspec(dllexport) int  block_compute_pow_target(mem_zone_ref_ptr ActualSpacing, mem_zone_ref_ptr nBits)
{
	hash_t				out_diff, Difflimit;
	unsigned int		nActualSpacing;
	unsigned int		pNBits, pBits;

	tree_mamanger_get_node_dword(ActualSpacing, 0, &nActualSpacing);
	tree_mamanger_get_node_dword(nBits, 0, &pBits);

	if (nActualSpacing == 0)
	{
		tree_manager_write_node_dword(nBits, 0, diff_limit);
		return 1;
	}

	if (nActualSpacing > MaxTargetSpacing )
		nActualSpacing = MaxTargetSpacing;

	pNBits = calc_new_target(nActualSpacing, TargetSpacing, TargetTimespan, pBits);

	SetCompact(pNBits, out_diff);
	SetCompact(diff_limit, Difflimit);
	if (memcmp_c(out_diff, Difflimit, sizeof(hash_t)) > 0)
		pNBits = diff_limit;

	tree_manager_write_node_dword(nBits, 0, pNBits);
	return 1;
}




__declspec(dllexport) int  get_tx_input(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr vin)
{
	int ret;
	mem_zone_ref txin_list = { (void *)0x00000000L };

	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsin"), 0x0B010000, &txin_list))return 0;
	ret = tree_manager_get_child_at(&txin_list, idx, vin);
	release_zone_ref(&txin_list);
	return ret;

}
__declspec(dllexport) int  get_tx_output(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr vout)
{
	int ret;
	mem_zone_ref txout_list = { (void *)0x00000000L };

	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsout"), 0x0B080000, &txout_list))return 0;
	ret = tree_manager_get_child_at(&txout_list, idx, vout);
	release_zone_ref(&txout_list);
	return ret;

}


__declspec(dllexport) int  load_tx_input(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr	in, mem_zone_ref_ptr tx_out)
{
	hash_t			prev_hash, blk_hash;
	int				ret=0;

	if (!get_tx_input(tx, idx, in))return 0;

	ret = tree_manager_get_child_value_hash(in, calc_crc32_c("txid"), prev_hash);
	if(ret)ret = load_tx(tx_out, blk_hash, prev_hash);
	if (!ret)release_zone_ref(in);
	return ret;

}
__declspec(dllexport) int  load_blk_tx_input(const char *blk_hash, unsigned int tx_ofset, unsigned int vin_idx, mem_zone_ref_ptr vout)
{
	int				ret=0;
	mem_zone_ref vin = { (void *)0x00000000L };
	mem_zone_ref tx = { (void *)0x00000000L }, prev_tx = { (void *)0x00000000L };

	if (!blk_load_tx_ofset(blk_hash, tx_ofset,&tx))return 0;

	if (load_tx_input(&tx, vin_idx, &vin, &prev_tx))
	{
		hash_t prevOutHash;
		unsigned int prevOutIdx;
		tree_manager_get_child_value_hash(&vin, calc_crc32_c("txid"), prevOutHash);
		tree_manager_get_child_value_i32(&vin, calc_crc32_c("idx"), &prevOutIdx);
		ret = get_tx_output(&prev_tx, prevOutIdx, vout);
		release_zone_ref(&prev_tx);
		release_zone_ref(&vin);
	}
	release_zone_ref(&tx);

	return ret;
}

__declspec(dllexport) int  load_tx_input_vout(mem_zone_ref_const_ptr tx, unsigned int vin_idx, mem_zone_ref_ptr vout)
{
	hash_t			prevOutHash;
	mem_zone_ref	vin = { (void *)0x00000000L };
	mem_zone_ref	prev_tx = { (void *)0x00000000L };
	unsigned int	prevOutIdx;
	int				ret = 0;

	if (!load_tx_input(tx, vin_idx, &vin, &prev_tx))return 0;
	
	tree_manager_get_child_value_hash(&vin, calc_crc32_c("txid"), prevOutHash);
	tree_manager_get_child_value_i32(&vin, calc_crc32_c("idx"), &prevOutIdx);
	ret = get_tx_output(&prev_tx, prevOutIdx, vout);
	release_zone_ref(&prev_tx);
	release_zone_ref(&vin);
	
	return ret;
}
int is_coinbase(mem_zone_ref_const_ptr tx)
{
	hash_t prev_hash;
	mem_zone_ref txin_list = { (void *)0x00000000L }, input = { (void *)0x00000000L };
	unsigned int oidx;
	int ret;

	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsin"), 0x0B010000, &txin_list))return 0;
	ret = tree_manager_get_child_at(&txin_list, 0, &input);
	release_zone_ref(&txin_list);
	if (!ret)return 0;

	ret = tree_manager_get_child_value_hash(&input, calc_crc32_c("txid"), prev_hash);
	if (ret)ret = tree_manager_get_child_value_i32(&input, calc_crc32_c("idx"), &oidx);
	release_zone_ref(&input);
	if (!ret)return 0;
	if ((!memcmp_c(prev_hash, null_hash, 32)) && (oidx >= 0xFFFF))
		return 1;

	return 0;
}



__declspec(dllexport) int  get_tx_input_hash(mem_zone_ref_ptr tx,unsigned int idx, hash_t hash)
{
	mem_zone_ref txin_list = { (void *)0x00000000L }, input = { (void *)0x00000000L};
	int			 ret;

	if (!tree_manager_find_child_node	(tx, calc_crc32_c("txsin"), 0x0B010000, &txin_list))return 0;
	
	ret = tree_manager_get_child_at(&txin_list, idx, &input);
	if (ret)
		tree_manager_get_child_value_hash(&input, calc_crc32_c("txid"), hash);

	release_zone_ref(&txin_list);
	release_zone_ref(&input);

	return ret;
}

__declspec(dllexport) int  get_tx_output_script(const hash_t tx_hash, unsigned int idx, struct string *script,uint64_t *amount)
{
	hash_t			blkhash;
	mem_zone_ref	tx = { (void *)0x00000000L }, vout = { (void *)0x00000000L };
	int				ret;

	if (!load_tx(&tx, blkhash, tx_hash))return 0;
	ret = get_tx_output(&tx, idx, &vout);
	if (ret)
	{
		ret = tree_manager_get_child_value_istr(&vout, calc_crc32_c("script"), script,0);
		ret = tree_manager_get_child_value_i64 (&vout, calc_crc32_c("value"), amount);
		release_zone_ref(&vout);
	}
	release_zone_ref(&tx);
	return ret;
}

__declspec(dllexport) int  get_tx_output_amount(mem_zone_ref_ptr tx, unsigned int idx, uint64_t *amount)
{
	mem_zone_ref	vout = { (void *)0x00000000L };
	int				ret;

	if (!get_tx_output(tx, idx, &vout))return 0;

	ret = tree_manager_get_child_value_i64(&vout, calc_crc32_c("value"), amount);
	release_zone_ref(&vout);
	return ret;
}

__declspec(dllexport) int  load_tx_output_amount(const hash_t tx_hash, unsigned int idx, uint64_t *amount)
{
	hash_t			blkhash;
	mem_zone_ref	tx = { (void *)0x00000000L }, vout = { (void *)0x00000000L };
	int				ret;
	if (!load_tx(&tx, blkhash, tx_hash))return 0;
	ret=get_tx_output_amount(&tx, idx, amount);
	release_zone_ref(&tx);
	return ret;
}

__declspec(dllexport) int   dump_tx_infos(mem_zone_ref_ptr tx)
{
	char 			chash[256],dd[32];
    hash_t			txsh;
    mem_zone_ref    out={(void *)0x00000000L};
    struct string   script={(void *)0x00000000L},oscript={(void *)0x00000000L},vpubK={(void *)0x00000000L},sign={(void *)0x00000000L};
	mem_zone_ref	in = { (void *)0x00000000L },prev_tx = { (void *)0x00000000L };
    int 			ret;
    unsigned char	hash_type;
    unsigned int    prevOutIdx,n;

	if (!load_tx_input(tx, 0, &in, &prev_tx))return 0;
    
	tree_manager_get_child_value_i32(&in, calc_crc32_c("idx"), &prevOutIdx);
	ret = get_tx_output				(&prev_tx, prevOutIdx, &out);
	release_zone_ref				(&prev_tx);
	
	if (ret)ret = tree_manager_get_child_value_istr		(&in	, calc_crc32_c("script"), &script, 0);
	if (ret)ret = get_insig_info						(&script, &sign, &vpubK, &hash_type);

	release_zone_ref	(&in);
	free_string			(&script);
	
	if (ret)ret = tree_manager_get_child_value_istr(&out, calc_crc32_c("script"), &oscript, 0);
	if (ret)ret = compute_tx_sign_hash(tx, 0, &oscript, hash_type, txsh);
    
    n = 0;
	while (n < 32)
	{
		chash[n * 2 + 0] = hex_chars[txsh[n] >> 0x04];
		chash[n * 2 + 1] = hex_chars[txsh[n] & 0x0F];
		n++;
	}
	chash[64] = 0;
			
	log_output("tx sign hash ");
    log_output(chash);
    log_output("\n");
    
    n = 0;
	while (n < vpubK.len)
	{
		unsigned char c=*(unsigned char *)(vpubK.str+n);
		chash[n * 2 + 0] = hex_chars[c >> 0x04];
		chash[n * 2 + 1] = hex_chars[c & 0x0F];
		n++;
	}
	chash[vpubK.len*2] = 0; 
	
	uitoa_s(vpubK.len,dd,10);
	
	log_output("tx sign pk ");
    log_output(chash);
    log_output(" len ");
    log_output(dd);
    log_output("\n");
           
    n = 0;
	while (n < sign.len)
	{
		unsigned char c=*(unsigned char *)(sign.str+n);
		chash[n * 2 + 0] = hex_chars[c >> 0x04];
		chash[n * 2 + 1] = hex_chars[c & 0x0F];
		n++;
	}
	chash[sign.len*2] = 0; 
	
	uitoa_s(sign.len,dd,10);
	
	log_output("tx sign ");
    log_output(chash);
    log_output(" len ");
    log_output(dd);
    log_output("\n");
    
    if(blk_check_sign(&sign, &vpubK, txsh))
    {
    	log_output("tx sign ok \n");
    }
    else
    {
    	log_output("tx sign fail \n");
    }
    
	free_string(&script);
	free_string(&oscript);
	free_string(&sign);
    

	return 1;
}

__declspec(dllexport) int   dump_txh_infos(const char *hash)
{
	mem_zone_ref	tx = { (void *)0x00000000L };
	hash_t 			blk_hash,tx_hash;
    int 			n=0;
    
  	
  	while (n<32)
	{
		char    hex[3];
		hex[0] = hash[(31-n) * 2 + 0];
		hex[1] = hash[(31-n) * 2 + 1];
		hex[2] = 0;
		tx_hash[n] = strtoul_c(hex, (void *)0x00000000L, 16);
		n++;
	}
  
    if(!load_tx(&tx,blk_hash,tx_hash))
    {
        log_output("unable to load tx ");
        log_output(hash);
        log_output("\n");
        return 0;
    }
    
    dump_tx_infos(&tx);
	release_zone_ref(&tx);
	
	return 1;

}

__declspec(dllexport) int  get_tx_output_addr(const hash_t tx_hash, unsigned int idx, btc_addr_t addr)
{
	hash_t			blkhash;
	mem_zone_ref	tx = { (void *)0x00000000L }, vout = { (void *)0x00000000L };
	int				ret;

	if (!load_tx(&tx, blkhash, tx_hash))return 0;
	ret = get_tx_output(&tx, idx, &vout);
	if (ret)
	{
		struct string  script;
		ret = tree_manager_get_child_value_istr(&vout, calc_crc32_c("script"), &script,0);
		if (ret)
		{
			get_out_script_address(&script, (void *)0x00000000L,addr);
			free_string(&script);
		}
		release_zone_ref(&vout);
	}
	release_zone_ref(&tx);
	return ret;
}


__declspec(dllexport) int  is_vout_null(mem_zone_ref_const_ptr tx, unsigned int idx)
{
	uint64_t		amount;
	struct string	script = { (void *)0x00000000L };
	mem_zone_ref vout = { (void *)0x00000000L };
	int			ret;
	if (!get_tx_output(tx, idx, &vout))return 0;

	ret = tree_manager_get_child_value_i64(&vout, calc_crc32_c("value"), &amount);
	if ((ret) && (amount > 0))
		ret = 0;

	if (ret)
		ret = tree_manager_get_child_value_istr(&vout, calc_crc32_c("script"), &script, 0);

	if ((ret) && (script.str[0] != 0))
		ret = 0;

	free_string(&script);
	release_zone_ref(&vout);

	return ret;
}

__declspec(dllexport) int  create_null_tx(mem_zone_ref_ptr tx,unsigned int time,unsigned int block_height)
{
	mem_zone_ref	script_node = { (void *)0x00000000L };
	struct string	nullscript = { (void *)0x00000000L };
	struct string	coinbasescript = { (void *)0x00000000L };
	char			null = 0;
	char			script[8];

	
	nullscript.str = &null;
	nullscript.len = 0;
	nullscript.size = 1;

	coinbasescript.str  = script;
	coinbasescript.len  = 4;
	coinbasescript.size = 4;

	script[0]							= 3;
	*((unsigned int *)(script + 1))		= block_height;

	new_transaction (tx, time);
	tx_add_input(tx, null_hash, 0xFFFFFFFF, &coinbasescript);
	tx_add_output	(tx,0, &nullscript);
	return 1;
}

__declspec(dllexport) int  is_tx_null(mem_zone_ref_const_ptr tx)
{
	struct string	script = { 0 };
	mem_zone_ref	vout = { (void *)0x00000000L };
	mem_zone_ref	txout_list = { (void *)0x00000000L };
	uint64_t		amount;
	int				ret, nc;


	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsout"), 0x0B080000, &txout_list))return -1;
	nc = tree_manager_get_node_num_children(&txout_list);
	if (nc == 0)
	{
		release_zone_ref(&txout_list);
		return -1;
	}
	ret = tree_manager_get_child_at(&txout_list, 0, &vout);
	release_zone_ref(&txout_list);
	if (!ret)return -1;
	ret = tree_manager_get_child_value_i64(&vout, calc_crc32_c("value"), &amount);
	if (ret)ret = tree_manager_get_child_value_istr(&vout, calc_crc32_c("script"), &script, 0);
	release_zone_ref(&vout);
	if (!ret)return -1;
	if ((nc == 1) && (amount == 0) && (script.str[0] == 0))
		ret = 1;
	else
		ret = 0;

	free_string(&script);
	return ret;
}
__declspec(dllexport) int  hash_equal(hash_t hash, const char *shash)
{
	int n = 0;
	while (n < 32)
	{
		char hex[3] = { shash[n * 2], shash[n * 2 + 1], 0 };
		unsigned char uc;
		uc = strtoul_c(hex, (void *)0x00000000L, 16);
		if (hash[31 - n] != uc)
			return 0;

		n++;
	}
	return 1;
}


__declspec(dllexport) int  get_hash_list(mem_zone_ref_ptr hdr_list, mem_zone_ref_ptr hash_list)
{
	mem_zone_ref		my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	hdr = (void *)0x00000000L;
	int					n = 0;

	tree_manager_create_node("hash list", 0x0B003000, hash_list);

	for (n = 0, tree_manager_get_first_child(hdr_list, &my_list, &hdr); ((hdr != (void *)0x00000000) && (hdr->zone != (void *)0x00000000)); n++, tree_manager_get_next_child(&my_list, &hdr))
	{
		hash_t blk_hash;

		tree_manager_get_child_value_hash(hdr, calc_crc32_c("blkHash"), blk_hash);
		tree_manager_set_child_value_bhash(hash_list, "hash", blk_hash);
	}
	return n;
}





__declspec(dllexport) int  compute_tx_sign_hash(mem_zone_ref_const_ptr tx, unsigned int nIn, const struct string *script, unsigned int hash_type, hash_t txh)
{
	hash_t				tx_hash;
	mem_zone_ref		txin_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L }, txTmp = { (void *)0x00000000L };
	mem_zone_ref_ptr	input = (void *)0x00000000L;
	size_t				length;
	unsigned char		*buffer;
	unsigned int		iidx;

	tree_manager_node_dup((void *)0x00000000L, tx, &txTmp,0xFFFFFFFF);
	if (!tree_manager_find_child_node(&txTmp, calc_crc32_c("txsin"), 0x0B010000, &txin_list))
	{
		log_output("sign hash no txin\n");
		return 0;
	}

	for (iidx = 0, tree_manager_get_first_child(&txin_list, &my_list, &input); ((input != (void *)0x00000000L) && (input->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &input), iidx++)
	{
		if (nIn == iidx)
			tree_manager_set_child_value_vstr(input, "script", script);
		else
			tree_manager_set_child_value_str(input, "script", "");
	}

	release_zone_ref(&txin_list);

	length									= get_node_size(&txTmp);
	buffer									= (unsigned char *)malloc_c(length + 4);
	*((unsigned int *)(buffer + length))	= hash_type;

	write_node				(&txTmp, buffer);
	mbedtls_sha256			(buffer, length + 4, tx_hash, 0);
	mbedtls_sha256			(tx_hash, 32, txh, 0);
	free_c					(buffer);
	release_zone_ref		(&txTmp);
	return 1;

}
__declspec(dllexport) int  blk_check_sign(const struct string *sign, const struct string *pubk, const hash_t hash)
{
	return check_sign(sign, pubk, hash);
}

__declspec(dllexport) int  check_tx_input_sig(mem_zone_ref_const_ptr tx, unsigned int nIn, struct string *vpubK)
{
	hash_t			txsh = { 0x0 };
	struct string	oscript = { (void *)0x00000000L }, script = { (void *)0x00000000L }, sign = { (void *)0x00000000L }, blksign = { (void *)0x00000000L };
	mem_zone_ref	prev_tx = { (void *)0x00000000L };
	mem_zone_ref	out = { (void *)0x00000000L }, in = { (void *)0x00000000L };
	unsigned int	prevOutIdx=0xFFFFFFFF;
	unsigned char	hash_type;
	int				ret = 0;

	if (!load_tx_input(tx, nIn, &in, &prev_tx))
	{
		log_message("could not load tx input '%txid%'", tx);
		return 0;
	}
	if (!tree_manager_get_child_value_i32(&in, calc_crc32_c("idx"), &prevOutIdx))
	{
		log_output("invalid tx input");
		return 0;
	}
	ret = get_tx_output(&prev_tx, prevOutIdx, &out);

	if (!ret)log_output("could not load tx output \n");

	release_zone_ref(&prev_tx);
	
	if (ret){
		ret = tree_manager_get_child_value_istr(&in, calc_crc32_c("script"), &script, 0);
		if (!ret)log_output("could input script\n");
	}
	if (ret)
	{
		ret = get_insig_info(&script, &sign, vpubK, &hash_type);
		if (!ret)log_output("no sig infos\n");
	}

	release_zone_ref	(&in);
	free_string			(&script);
	

	if (ret)
	{
		ret = tree_manager_get_child_value_istr	(&out, calc_crc32_c("script"), &oscript, 0);
		if (!ret)log_output						("no output script\n");
	}
	if (ret)
	{
		ret = compute_tx_sign_hash(tx, nIn, &oscript, hash_type, txsh);
		if (!ret)log_output("compute sign hash failed\n");
	}
	if (ret)
	{
		if (vpubK->len < 31)
		{
			btc_addr_t addr;
			free_string(vpubK);
			ret = get_out_script_address(&oscript, vpubK, addr);
			if (!ret)log_output("output address failed\n");
		}
		if (ret)
		{
			ret = blk_check_sign(&sign, vpubK, txsh);
			if (!ret)
			{
				char th[65] = { 0 };
				char txh[65] = { 0 };
				unsigned int n;

				tree_manager_get_child_value_str(tx, calc_crc32_c("txid"), txh, 65, 0);

				n = 0;
				while (n < 32)
				{
					th[n * 2 + 0] = hex_chars[txsh[n] >> 0x04];
					th[n * 2 + 1] = hex_chars[txsh[n] & 0x0F];
					n++;
				}
				th[64] = 0;
				log_output("signature check failed '");
				log_output(th);
				log_output("' '");
				log_output(txh);
				log_output("'\n");
			}
		}
	}

	free_string			(&oscript);
	release_zone_ref	(&out);
	free_string			(&sign);
	release_zone_ref	(&out);

	return ret;
}

__declspec(dllexport) int  tx_sign(mem_zone_ref_const_ptr tx, unsigned int nIn, unsigned int hashType, const struct string *sign_seq, const struct string *inPubKey)
{
	hash_t				tx_hash;
	struct				string oscript = { (void *)0x00000000L };
	mem_zone_ref		vin = { (void *)0x00000000L }, vout = { (void *)0x00000000L };
	int					isObj =0,ret = 0;

	get_tx_input(tx, nIn, &vin);

	if (!tree_manager_get_child_value_i32(&vin, calc_crc32_c("isAppObj"), &isObj))
		isObj = 0;

	if (isObj)
	{
		btc_addr_t			addr;
		struct string		pubk = { (void *)0x00000000L };
		struct string		sign = { 0 };
		unsigned char		htype;

		get_tx_output						(tx, 0, &vout);
		tree_manager_get_child_value_istr	(&vout, calc_crc32_c("script"), &oscript, 0);
		get_out_script_address				(&oscript, &pubk, addr);


		ret = (pubk.len == 33) ? 1 : 0;
		if (ret)ret = compute_tx_sign_hash	(tx, nIn, &oscript, hashType, tx_hash);
		if (ret)ret = parse_sig_seq			(sign_seq, &sign, &htype, 1);
		if (ret)ret = check_sign			(&sign, &pubk, tx_hash);
		if (ret)
		{
			struct string sscript		= { (void *)0x00000000L };
			mem_zone_ref script_node	= { (void *)0x00000000L };

			tree_manager_create_node		 ("script", 0x0B200000, &script_node);
			tree_manager_set_child_value_vstr(&script_node, "var1", sign_seq);
			serialize_script				 (&script_node, &sscript);
			release_zone_ref				 (&script_node);

			tree_manager_set_child_value_vstr(&vin, "script", &sscript);
			free_string						 (&sscript);
		}
		free_string		(&sign);
		free_string		(&pubk);
		release_zone_ref(&vout);
		free_string		(&oscript);
	}
	else if (load_tx_input_vout(tx, nIn, &vout))
	{
		tree_manager_get_child_value_istr	(&vout	, calc_crc32_c("script"), &oscript , 0);
		if (compute_tx_sign_hash(tx, nIn, &oscript, hashType, tx_hash))
		{
			btc_addr_t		addr;
			struct string	pubk = { (void *)0x00000000L };
			get_out_script_address(&oscript, &pubk, addr);
			if (pubk.len > 0)
			{
				struct string			sign = { 0 };
				unsigned char			htype;
				if (parse_sig_seq(sign_seq, &sign, &htype, 1))
				{
					ret = check_sign	(&sign, &pubk, tx_hash);
					free_string			(&sign);
					if (ret)
					{
						struct string sscript = { (void *)0x00000000L };
						mem_zone_ref script_node = { (void *)0x00000000L };
						tree_manager_create_node			("script", 0x0B200000, &script_node);
						tree_manager_set_child_value_vstr	(&script_node, "var1", sign_seq);
						serialize_script					(&script_node, &sscript);
						release_zone_ref					(&script_node);
						tree_manager_set_child_value_vstr	(&vin, "script", &sscript);
						free_string							(&sscript);
					}
				}
				free_string(&pubk);
			}
			else if ((inPubKey != (void *)0x00000000L) && (inPubKey->str!=(void *)0x00000000L))
			{
				btc_addr_t				inAddr;
				struct string			sign = { (void *)0x00000000L };
				unsigned char			htype;

				key_to_addr						(inPubKey->str, inAddr);
				ret = (memcmp_c(inAddr, addr, sizeof(btc_addr_t)) == 0) ? 1 : 0;
				if (ret)ret = parse_sig_seq		(sign_seq, &sign, &htype, 1);
				if (ret)ret = check_sign		(&sign, inPubKey, tx_hash);
				if (ret)
				{
					mem_zone_ref script_node = { (void *)0x00000000L };
						
					if(tree_manager_create_node("script", 0x0B200000, &script_node))
					{
						struct string sscript = { (void *)0x00000000L };

						tree_manager_set_child_value_vstr	(&script_node, "var1", sign_seq);
						tree_manager_set_child_value_vstr	(&script_node, "var2", inPubKey);
						serialize_script					(&script_node, &sscript);
						tree_manager_set_child_value_vstr	(&vin, "script", &sscript);
						release_zone_ref					(&script_node);
						free_string							(&sscript);
					}
				}
				free_string						(&sign);
			}
			else
				ret=0;

			free_string(&oscript);
		}
		release_zone_ref(&vout);
	}

	release_zone_ref(&vin);
	return ret;
}

__declspec(dllexport) int  get_type_infos(struct string *script, char *name, unsigned int *id, unsigned int *flags)
{
	struct string ktype = { (void *)0x00000000L }, kname = { (void *)0x00000000L }, kflags = { (void *)0x00000000L };
	size_t offset = 0;
	int ret = 0;
	
	kname = get_next_script_var(script, &offset);
	if ((kname.len < 3) || (kname.len>32))
	{
		free_string(&kname);
		return 0;
	}
	strcpy_cs(name, 32, kname.str);

	ktype = get_next_script_var(script, &offset);
	if (ktype.len == 4)
	{
		*id = *((unsigned int *)(ktype.str));
		ret = 1;
	}
	else if (ktype.len == 2)
	{
		*id = *((unsigned short *)(ktype.str));
		ret = 1;
	}
	else if (ktype.len == 1)
	{
		*id = *((unsigned char *)(ktype.str));
		ret = 1;
	}

	kflags = get_next_script_var(script, &offset);

	if (kflags.len == 0)
		*flags = 0;
	else if (kflags.len == 1)
		*flags = *((unsigned char *)(kflags.str));

	free_string(&kflags);
	free_string(&kname);
	free_string(&ktype);

	return ret;
}

__declspec(dllexport) int  get_app_types(mem_zone_ref_ptr app, mem_zone_ref_ptr types)
{
	mem_zone_ref	 txout_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr out = (void *)0x00000000L;
	int				 ret = 0;

	if (!tree_manager_find_child_node(app, calc_crc32_c("txsout"), 0x0B080000, &txout_list))return 0;
	
	for (tree_manager_get_first_child(&txout_list, &my_list, &out); ((out != (void *)0x00000000) && (out->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &out))
	{
		unsigned int app_item;
		if (!tree_manager_get_child_value_i32(out, calc_crc32_c("app_item"), &app_item))continue;
		if (app_item == 1)
		{
			mem_zone_ref app_types = { (void *)0x00000000L };

			tree_manager_find_child_node(out, calc_crc32_c("types"), 0x0B004000, types);
			dec_zone_ref				(out);
			release_zone_ref			(&my_list);
			release_zone_ref			(&txout_list);
			ret = 1;
			break;
		}
	}
	release_zone_ref(&txout_list);
	return ret;
}

__declspec(dllexport) int  get_app_scripts(mem_zone_ref_ptr app, mem_zone_ref_ptr scripts)
{
	mem_zone_ref	 txout_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr out = (void *)0x00000000L;
	int				 ret = 0;

	if (!tree_manager_find_child_node(app, calc_crc32_c("txsout"), 0x0B080000, &txout_list))return 0;

	for (tree_manager_get_first_child(&txout_list, &my_list, &out); ((out != (void *)0x00000000) && (out->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &out))
	{
		unsigned int app_item;
		if (!tree_manager_get_child_value_i32(out, calc_crc32_c("app_item"), &app_item))continue;
		if (app_item == 5)
		{
			ret=tree_manager_find_child_node(out, calc_crc32_c("scripts"), 0x08008000, scripts);
			dec_zone_ref				(out);
			release_zone_ref			(&my_list);
			break;
		}
	}
	release_zone_ref(&txout_list);
	return ret;
}
int add_app_tx_type(mem_zone_ref_ptr app, mem_zone_ref_ptr typetx)
{
	mem_zone_ref txout_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L }, type_def = { (void *)0x00000000L };
	struct string typeStr = { 0 }, typeName = { 0 }, typeId = { 0 }, Flags = { 0 };
	mem_zone_ref_ptr out = (void *)0x00000000L;
	size_t offset = 0;
	unsigned int type_id, flags;
	int ret = 0;

	if (!get_tx_output(typetx, 0, &type_def))return 0;

	if (!tree_manager_find_child_node(app, calc_crc32_c("txsout"), 0x0B080000, &txout_list)){
		release_zone_ref(&type_def);
		return 0;
	}

	tree_manager_get_child_value_istr(&type_def, calc_crc32_c("script"), &typeStr, 0);

	typeName = get_next_script_var(&typeStr, &offset);
	typeId	 = get_next_script_var(&typeStr, &offset);
	

	free_string	(&typeStr);

	if (typeId.len != 4)
	{
		free_string		(&typeName);
		free_string		(&typeId);
		release_zone_ref(&type_def);
		release_zone_ref(&txout_list);
		return 0;
	}

	
	type_id = *((unsigned int *)(typeId.str));
	
	tree_manager_set_child_value_vstr(typetx, "typeName", &typeName);
	tree_manager_set_child_value_i32 (typetx , "typeId", type_id);



	for (tree_manager_get_first_child(&txout_list, &my_list, &out); ((out != (void *)0x00000000) && (out->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &out))
	{
		unsigned int app_item;
		if (!tree_manager_get_child_value_i32(out, calc_crc32_c("app_item"), &app_item))continue;
		if (app_item == 1)
		{
			mem_zone_ref types = { (void *)0x00000000L };

			if (!tree_manager_find_child_node(out, calc_crc32_c("types"), 0x0B004000, &types))
				tree_manager_add_child_node(out, "types", 0x0B004000, &types);

			tree_manager_node_add_child	(&types, typetx);

			release_zone_ref			(&types);

			dec_zone_ref				(out);
			release_zone_ref			(&my_list);
			ret = 1;
			break;
		}
	}

	free_string		(&Flags);
	free_string		(&typeName);
	free_string		(&typeId);
	release_zone_ref(&txout_list);
	release_zone_ref(&type_def);
	return ret;
}

int add_app_script(mem_zone_ref_ptr app, mem_zone_ref_ptr script_vars)
{
	mem_zone_ref txout_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr out = (void *)0x00000000L;

	int ret = 0;

	if (!tree_manager_find_child_node(app, calc_crc32_c("txsout"), 0x0B080000, &txout_list))return 0;
	

	for (tree_manager_get_first_child(&txout_list, &my_list, &out); ((out != (void *)0x00000000) && (out->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &out))
	{
		unsigned int app_item;
		if (!tree_manager_get_child_value_i32(out, calc_crc32_c("app_item"), &app_item))continue;
		if (app_item == 5)
		{
			mem_zone_ref scripts = { (void *)0x00000000L };

			if (!tree_manager_find_child_node(out, calc_crc32_c("scripts"), 0x08008000, &scripts))
				tree_manager_add_child_node(out, "scripts", 0x08008000, &scripts);

			tree_manager_node_add_child(&scripts, script_vars);

			release_zone_ref(&scripts);

			dec_zone_ref(out);
			release_zone_ref(&my_list);
			ret = 1;
			break;
		}
	}
	release_zone_ref(&txout_list);

	return ret;
}


__declspec(dllexport) int  is_app_root(mem_zone_ref_ptr tx)
{
	mem_zone_ref		txin_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	input = (void *)0x00000000L;
	unsigned int		iidx,app_root;


	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsin"), 0x0B010000, &txin_list))
		return 0;

	app_root=0;

	for (iidx = 0, tree_manager_get_first_child(&txin_list, &my_list, &input); ((input != (void *)0x00000000L) && (input->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &input), iidx++)
	{
		hash_t				prev_hash;
		unsigned int		oidx = 0;
		int					n = 0;

		memset_c(prev_hash, 0, sizeof(hash_t));

		tree_manager_get_child_value_hash	(input, calc_crc32_c("txid"), prev_hash);
		tree_manager_get_child_value_i32	(input, calc_crc32_c("idx") , &oidx);

		if ((!memcmp_c(prev_hash, null_hash, 32)) && (oidx >= 0xFFFF))
		{
			struct string script={0},var={0};
			size_t offset=0;

			tree_manager_get_child_value_istr	(input, calc_crc32_c("script"), &script,16);
			var = get_next_script_var			(&script,&offset);
			free_string							(&script);

			if(var.len>0)
			{
				if(!strcmp_c(var.str,"AppRoot"))
					app_root=1;
			}
			free_string(&var);
		}
	}

	release_zone_ref(&txin_list);

	return app_root;
}



int tx_is_app_item(const hash_t txh,unsigned int oidx,mem_zone_ref_ptr app_tx,unsigned char *val)
{
	struct string	oscript = { 0 }, my_val = { (void *)0x00000000L };
	mem_zone_ref	prevout = { (void *)0x00000000L };
	int				ret = 0;

	if (!tree_find_child_node_by_member_name_hash(&apps, 0x0B008000, "txid", txh, app_tx))return 0;
	
	get_tx_output						(app_tx, oidx, &prevout);
	if (!tree_manager_get_child_value_istr(&prevout, calc_crc32_c("script"), &oscript, 0))
	{
		release_zone_ref(app_tx);
		return 0;
	}

	if (get_out_script_return_val(&oscript, &my_val))
	{
		if ((my_val.len == 1) && (*((unsigned char*)(my_val.str)) > 0) && (*((unsigned char*)(my_val.str)) < 6))
		{
			*val = *((unsigned char*)(my_val.str));
			ret = 1;
		}

		free_string(&my_val);
	}
	free_string(&oscript);
	release_zone_ref(&prevout);

	if (!ret)
		release_zone_ref(app_tx);

	return ret;
}

int tx_is_app_child(hash_t txh, unsigned int oidx,struct string *appname)
{
	hash_t bh;
	mem_zone_ref tx = { (void *)0x00000000L }, vin = { (void *)0x00000000L }, app_tx = { (void *)0x00000000L };
	int ret = 0;

	if (oidx > 0)return 0;
	if (!load_tx(&tx, bh, txh))return 0;

	if (get_tx_input(&tx, 0, &vin))
	{
		hash_t	prev_hash;
		unsigned int oidx;
		unsigned char app_item;
		tree_manager_get_child_value_hash	(&vin, calc_crc32_c("txid"), prev_hash);
		tree_manager_get_child_value_i32	(&vin, calc_crc32_c("idx"), &oidx);

		if (tx_is_app_item(prev_hash, oidx, &app_tx, &app_item))
		{
			tree_manager_get_child_value_istr(&app_tx, calc_crc32_c("appName"), appname,0);
			ret = 1;
			release_zone_ref(&app_tx);
		}
		release_zone_ref(&vin);
	}

	release_zone_ref(&tx);

	return ret;
}

__declspec(dllexport) int  tx_is_app_file(mem_zone_ref_ptr tx, struct string *appName,mem_zone_ref_ptr file)
{
	hash_t			txh;
	struct string	oscript = { 0 }, my_val = { (void *)0x00000000L };
	mem_zone_ref	input = { (void *)0x00000000L }, prevout = { (void *)0x00000000L }, app_tx = { (void *)0x00000000L };
	unsigned int	oidx;
	int				ret = 0;

	if (!get_tx_input(tx, 0, &input))return 0;
	tree_manager_get_child_value_hash(&input, calc_crc32_c("txid"), txh);
	tree_manager_get_child_value_i32(&input, calc_crc32_c("idx"), &oidx);
	release_zone_ref(&input);

	if (!tree_find_child_node_by_member_name_hash(&apps, 0x0B008000, "txid", txh, &app_tx))return 0;

	get_tx_output						(&app_tx, oidx, &prevout);
	

	tree_manager_get_child_value_istr	(&prevout, calc_crc32_c("script"), &oscript, 0);
	release_zone_ref			(&prevout);
	if (get_out_script_return_val(&oscript, &my_val))
	{
		if ((my_val.len == 1) && ( (*((unsigned char*)(my_val.str))) ==3))
		{
			struct string fscript = { 0 };

			get_tx_output						(tx, 0, &prevout);
			tree_manager_get_child_value_istr	(&prevout, calc_crc32_c("script"), &fscript, 0);
			ret	=	get_script_file				(&fscript, file);

			if (ret)tree_manager_get_child_value_istr(&app_tx, calc_crc32_c("appName"), appName, 0);

			release_zone_ref					(&prevout);
			free_string							(&fscript);
		}
		free_string(&my_val);
	}
	free_string(&oscript);
	
	release_zone_ref(&app_tx);

	return ret;
}

__declspec(dllexport) int  get_tx_file(mem_zone_ref_ptr tx,mem_zone_ref_ptr hash_list)
{
	hash_t			tx_hash;
	mem_zone_ref	new_file = { (void *)0x00000000L };

	if (!tree_manager_find_child_node(tx, calc_crc32_c("fileDef"), 0x00000400, (void *)0x00000000L))
	{ 
		return 0; 
	
	}
	tree_manager_get_child_value_hash(tx, calc_crc32_c("txid"), tx_hash);

	if (tree_manager_add_child_node(hash_list, "file", 0x0A000080, &new_file))
	{
		tree_manager_write_node_hash(&new_file, 0, tx_hash);
		release_zone_ref(&new_file);
	}

	return 1;
}

int obj_new(mem_zone_ref_ptr type, const char *objName, struct string *script, mem_zone_ref_ptr obj)
{
	mem_zone_ref		type_outs = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	struct string		objData = { 0 };
	mem_zone_ref_ptr	key = (void *)0x00000000L;
	unsigned int		type_id, oidx;

	tree_manager_get_child_value_i32(type, calc_crc32_c("typeId"), &type_id);

	tree_manager_find_child_node(type, calc_crc32_c("txsout"), 0x0B080000, &type_outs);
	tree_manager_create_node(objName, type_id, obj);

	for (oidx = 0, tree_manager_get_first_child(&type_outs, &my_list, &key); ((key != (void *)0x00000000) && (key->zone != (void *)0x00000000)); oidx++, tree_manager_get_next_child(&my_list, &key))
	{
		char			KeyName[32];
		struct string	KeyStr = { 0 };
		unsigned int	KeyId, flags;
		uint64_t		amount;

		if (oidx == 0)continue;
		tree_manager_get_child_value_i64(key, calc_crc32_c("value"), &amount);
		if (amount != 0)continue;

		tree_manager_get_child_value_istr(key, calc_crc32_c("script"), &KeyStr, 0);

		if (get_type_infos(&KeyStr, KeyName, &KeyId, &flags))
		{
			if (KeyId == 0x00000001)
				KeyId = 0x0B000100;
			tree_manager_add_child_node(obj, KeyName, KeyId, (void *)0x00000000L);
		}
		free_string(&KeyStr);
	}
	release_zone_ref(&type_outs);

	if (get_out_script_return_val(script, &objData))
	{
		unserialize_children(obj, objData.str, objData.len);
		free_string(&objData);
		return 1;
	}

	return 0;
}


int is_obj_child(const hash_t ph,unsigned int pidx,mem_zone_ref_ptr prev_tx,struct string *appName)
{
	hash_t				pBlock, pid;
	mem_zone_ref		prevout = { (void *)0x00000000L }, prev_input = { (void *)0x00000000L }, app = { (void *)0x00000000L };
	struct string		oscript = { 0 };
	int					ret=0;


	if (!tree_find_child_node_by_member_name_hash(&blkobjs, 0x0B008000, "txid", ph, prev_tx))
	{
		if (!load_tx(prev_tx, pBlock, ph))return -1;
	}

	get_tx_input(prev_tx, 0, &prev_input);

	tree_manager_get_child_value_hash(&prev_input, calc_crc32_c("txid"), pid);

	if ((pidx == 0) && tree_find_child_node_by_member_name_hash(&apps, 0x0B008000, "txid", pid, &app))
	{
		mem_zone_ref		app_out = { (void *)0x00000000L };
		unsigned int		pidx;

		tree_manager_get_child_value_i32(&prev_input, calc_crc32_c("idx"), &pidx);

		if (get_tx_output(&app, pidx, &app_out))
		{
			struct string app_script = { (void *)0x00000000L }, val = { (void *)0x00000000L };

			tree_manager_get_child_value_istr(&app_out, calc_crc32_c("script"), &app_script, 0);

			if (get_out_script_return_val(&app_script, &val))
			{
				if ((val.len == 1) && (*((unsigned char *)(val.str)) == 2))
				{
					tree_manager_get_child_value_istr(&app, calc_crc32_c("appName"), appName, 0);
					ret = 1;
				}
				free_string(&val);
			}
			free_string		(&app_script);
			release_zone_ref(&app_out);
		}
		release_zone_ref(&app);
	}
	release_zone_ref(&prev_input);

	

	return ret;
}

__declspec(dllexport) int  get_app_type_idxs(const char *appName, unsigned int type_id, mem_zone_ref_ptr keys)
{
	mem_zone_ref app = { (void *)0x00000000L }, types = { (void *)0x00000000L }, type = { (void *)0x00000000L }, type_outs = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr key;
	int ret = 0;
	
	if (!tree_manager_find_child_node(&apps, calc_crc32_c(appName), 0x0B008000, &app))return 0;

	get_app_types(&app, &types);

	if (tree_find_child_node_by_id_name(&types, 0x0B008000, "typeId", type_id, &type))
	{
		unsigned int oidx;
		tree_manager_find_child_node(&type, calc_crc32_c("txsout"), 0x0B080000, &type_outs);

		for (oidx = 0, tree_manager_get_first_child(&type_outs, &my_list, &key); ((key != (void *)0x00000000) && (key->zone != (void *)0x00000000)); oidx++, tree_manager_get_next_child(&my_list, &key))
		{
			char			KeyName[32];
			struct string	KeyStr = { 0 };
			unsigned int	KeyId, flags;
			uint64_t		amount;

			if (oidx == 0)continue;
			tree_manager_get_child_value_i64(key, calc_crc32_c("value"), &amount);
			if (amount != 0)continue;
			tree_manager_get_child_value_istr(key, calc_crc32_c("script"), &KeyStr, 0);

			if (get_type_infos(&KeyStr, KeyName, &KeyId, &flags))
			{
				if (flags & 1)
				{
					mem_zone_ref nk = { 0 };
					tree_manager_add_child_node		(keys, KeyName, KeyId, &nk);
					tree_manager_write_node_dword	(&nk, 0, flags);
					release_zone_ref				(&nk);
				}
			}
			free_string(&KeyStr);
		}
		release_zone_ref(&type_outs);
	}

	release_zone_ref(&type);
	release_zone_ref(&types);
	release_zone_ref(&app);
	return ret;
}

__declspec(dllexport) int  check_app_obj_unique(const char *appName, unsigned int type_id, mem_zone_ref_ptr obj)
{
	mem_zone_ref app = { (void *)0x00000000L }, types = { (void *)0x00000000L }, type = { (void *)0x00000000L }, type_outs = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr key;
	unsigned int unique;
	int ret = 0;

	if (!tree_manager_find_child_node(&apps, calc_crc32_c(appName), 0x0B008000, &app))return 0;

	unique = 1;

	get_app_types(&app, &types);

	if (tree_find_child_node_by_id_name(&types, 0x0B008000, "typeId", type_id, &type))
	{
		unsigned int oidx;
		tree_manager_find_child_node(&type, calc_crc32_c("txsout"), 0x0B080000, &type_outs);

		for (oidx = 0, tree_manager_get_first_child(&type_outs, &my_list, &key); ((key != (void *)0x00000000) && (key->zone != (void *)0x00000000)); oidx++, tree_manager_get_next_child(&my_list, &key))
		{
			char			KeyName[32];
			struct string	KeyStr = { 0 };
			unsigned int	KeyId, flags;
			uint64_t		amount;

			if (oidx == 0)continue;
			tree_manager_get_child_value_i64(key, calc_crc32_c("value"), &amount);
			if (amount != 0)continue;
			tree_manager_get_child_value_istr(key, calc_crc32_c("script"), &KeyStr, 0);

			if (get_type_infos(&KeyStr, KeyName, &KeyId, &flags))
			{
				if (flags & 1)
				{
					char typestr[16];

					uitoa_s			(type_id, typestr, 16, 16);

					switch (KeyId)
					{
						case 0x0B000100:
						{
							struct string	val = { 0 };
							hash_t			h;
							tree_manager_get_child_value_istr(obj, calc_crc32_c(KeyName), &val, 0);

							if (find_index_str(appName, typestr, KeyName, &val, h))
								unique = 0;
						}
						break;
					}
				}
			}
			free_string(&KeyStr);

			if (!unique)
			{
				dec_zone_ref(key);
				release_zone_ref(&my_list);
				break;
			}
		}
		release_zone_ref(&type_outs);
	}

	release_zone_ref(&type);
	release_zone_ref(&types);
	release_zone_ref(&app);
	return unique;
}



__declspec(dllexport) int  get_app_type_key(const char *appName, unsigned int type_id, const char *kname, unsigned int *ktype, unsigned int *Flags)
{
	mem_zone_ref app = { (void *)0x00000000L }, types = { (void *)0x00000000L }, type = { (void *)0x00000000L }, type_outs = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr key;
	int ret=0;


	if (!tree_manager_find_child_node(&apps, calc_crc32_c(appName), 0x0B008000, &app))return 0;

	get_app_types					(&app, &types);

	if (tree_find_child_node_by_id_name(&types, 0x0B008000, "typeId", type_id, &type))
	{
		unsigned int oidx;
		tree_manager_find_child_node(&type, calc_crc32_c("txsout"), 0x0B080000, &type_outs);

		for (oidx = 0, tree_manager_get_first_child(&type_outs, &my_list, &key); ((key != (void *)0x00000000) && (key->zone != (void *)0x00000000)); oidx ++, tree_manager_get_next_child(&my_list, &key))
		{
			char			KeyName[32];
			struct string	KeyStr = { 0 };
			unsigned int	KeyId, flags;
			uint64_t		amount;

			if (oidx == 0)continue;
			tree_manager_get_child_value_i64(key, calc_crc32_c("value"), &amount);
			if (amount != 0)continue;
			tree_manager_get_child_value_istr(key, calc_crc32_c("script"), &KeyStr, 0);

			if (get_type_infos(&KeyStr, KeyName, &KeyId, &flags))
			{
				if (!strcmp_c(KeyName, kname))
				{
					*ktype = KeyId;
					*Flags = flags;

					free_string		(&KeyStr);
					dec_zone_ref	(key);
					release_zone_ref(&my_list);
					ret = 1;
					break;
				}
			}
			free_string(&KeyStr);
		}
		release_zone_ref(&type_outs);
	}

	release_zone_ref(&type);
	release_zone_ref(&types);
	release_zone_ref(&app);

	return ret;
}

__declspec(dllexport) int  get_block_tree(node **blktree)
{
	*blktree = blk_root;

	return 1;
}

__declspec(dllexport) int  check_tx_inputs(mem_zone_ref_ptr tx, uint64_t *total_in, unsigned int *is_coinbase,unsigned int check_sig)
{
	mem_zone_ref		txin_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	input = (void *)0x00000000L;
	unsigned int		iidx, has_app, is_app_item;
	int ret;

	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsin"), 0x0B010000, &txin_list))
		return 0;

	is_app_item = 0;
	has_app		= 0;
	*total_in	= 0;

	for (iidx = 0, tree_manager_get_first_child(&txin_list, &my_list, &input); ((input != (void *)0x00000000L) && (input->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &input), iidx++)
	{
		tree_entry			et;
		btc_addr_t			addr;
		hash_t				pBlock;
		mem_zone_ref		prev_tx = { (void *)0x00000000L };
		struct string		appName = { 0 };
		uint64_t			amount = 0;
		unsigned char		app_item;
		int					n= 0;
		unsigned int		*et_ptr=&et[8];

		memset_c(et			, 0, sizeof(tree_entry));
		memset_c(pBlock		, 0, sizeof(hash_t));

		if (!tree_manager_get_child_value_hash(input, calc_crc32_c("txid"), et))
		{
			log_output("chk tx bad txin txid\n");
			release_zone_ref(&my_list);
			dec_zone_ref(input);
			release_zone_ref(&txin_list);
			return 0;
		}
		if (!tree_manager_get_child_value_i32(input, calc_crc32_c("idx"), et_ptr))
		{
			log_output("chk tx bad txin idx\n");
			release_zone_ref(&my_list);
			dec_zone_ref(input);
			release_zone_ref(&txin_list);
			return 0;

		}

		ret = 0;


		if ((!memcmp_c(et, null_hash, 32)) && (et[8] >= 0xFFFF))
		{
			if ((*is_coinbase) == 0)
			{
				*is_coinbase = 1;
				continue;
			}
			release_zone_ref	(&my_list);
			dec_zone_ref		(input);
			release_zone_ref	(&txin_list);
			return 0;
		}
		else if ((has_root_app == 1) && (!memcmp_c(et, app_root_hash, sizeof(hash_t))))
		{
			struct string script = { 0 };

			ret = (has_app == 0) ? 1 : 0;
			if (ret)ret = tree_manager_get_child_value_istr(input, calc_crc32_c("script"), &script, 0);
			if (ret)ret = get_app_name(&script, &appName);
			if (ret)ret = (appName.len >= 3) ? 1 : 0;
			if (ret)ret = (appName.len < 32) ? 1 : 0;
			if (ret)ret = tree_manager_set_child_value_str(tx, "AppName", appName.str);
			if (ret)ret = tree_manager_set_child_value_bool(input, "isApp", 1);
			if (ret)ret = tree_manager_set_child_value_str(input, "appName", appName.str);
			free_string(&appName);
			free_string(&script);
			if(ret)has_app = 1;
		}
		else if (tx_is_app_item((unsigned char *)et, et[8], &prev_tx, &app_item))
		{
			unsigned char	hash_type;
			
			if (is_app_item)
			{
				log_output("app item already found \n");
				ret = 0;
			}
			else
			{
				char *cappn;
				struct string	oscript = { 0 };
				mem_zone_ref	prevout = { (void *)0x00000000L };

				tree_manager_get_child_value_istr	(&prev_tx, calc_crc32_c("appName"), &appName,0);
				log_output							("new app item for '");
				log_output							(appName.str);
				log_output							("'\n");

				cappn=appName.str;

				ret = tree_manager_find_child_node(&apps, calc_crc32_c(cappn), 0x0B008000, (void *)0x00000000L);

				if (ret)
				{
					get_tx_output					 (&prev_tx, et[8], &prevout);
					tree_manager_get_child_value_istr(&prevout, calc_crc32_c("script"), &oscript, 0);

					switch (app_item)
					{
						case 1:
						case 4:
						case 5:
						{
							hash_t			txh;
							struct string	script = { (void *)0x00000000L }, sign = { (void *)0x00000000L }, vpubK = { (void *)0x00000000L };

							tree_manager_get_child_value_istr	(input, calc_crc32_c("script"), &script, 0);
							ret = get_insig_info				(&script, &sign, &vpubK, &hash_type);
							free_string							(&script);

							if (ret)
							{
								if (vpubK.len == 0)
								{
									ret = get_out_script_address(&oscript, &vpubK, addr);
									if (!ret)log_output("unable to parse input addr \n");
								}
								else
								{
									ret = check_txout_key(&prevout, (unsigned char *)vpubK.str, addr);
									if (!ret)log_output("check input pkey hash failed\n");
								}
							}

							if (ret)ret = compute_tx_sign_hash(tx, iidx, &oscript, hash_type, txh);
							if (ret)ret = check_sign(&sign, &vpubK, txh);

							free_string(&sign);
							free_string(&vpubK);

							if (ret)ret = tree_manager_set_child_value_i32(tx, "app_item", app_item);
							if (ret)is_app_item = 1;
							if (ret)
							{
								if (app_item == 1)
									tree_manager_set_child_value_vstr(tx, "appType", &appName);

								if (app_item == 4)
									tree_manager_set_child_value_vstr(tx, "appLayout", &appName);

								if (app_item == 5)
									tree_manager_set_child_value_vstr(tx, "appModule", &appName);
							}
					
						}
						break;
						case 2:
						{
							struct string script = { 0 }, pkey = { 0 };
							struct string sign = { 0 }, bsign = { 0 };

							tree_manager_get_child_value_istr(input, calc_crc32_c("script"), &script, 0);
							ret = get_insig_info(&script, &sign, &pkey, &hash_type);
							if(ret) ret = (pkey.len == 0) ? 1 : 0;
							if (ret)ret = tree_manager_set_child_value_vstr(tx, "appObj", &appName);
							if (ret)ret = tree_manager_set_child_value_vstr(tx, "ObjSign", &sign);
							if (ret)ret = tree_manager_set_child_value_i32(tx, "app_item", app_item);
							if (ret)is_app_item = 1;
							if (ret)tree_manager_node_add_child(&blkobjs, tx);

							free_string(&script);
							free_string(&sign);
							free_string(&pkey);

						}
						break;
						case 3:
							tree_manager_set_child_value_vstr(tx, "appFile", &appName);
							ret = tree_manager_set_child_value_i32(tx, "app_item", app_item);
							if (ret)is_app_item = 1;
						break;
					}
					free_string(&oscript);
					release_zone_ref(&prevout);
				}
				if(ret)tree_manager_set_child_value_vstr(input, "srcapp", &appName);

				free_string(&appName);
			}
			release_zone_ref(&prev_tx);
			if (!ret)
			{
				log_output("new app failed \n");
				release_zone_ref(&my_list);
				dec_zone_ref(input);
				release_zone_ref(&txin_list);
			}
		}
		else if (is_obj_child((unsigned char *)et, et[8], &prev_tx, &appName) == 1)
		{
			mem_zone_ref		prevout = { (void *)0x00000000L };
			struct string		script = { (void *)0x00000000L }, sign = { (void *)0x00000000L }, vpubK = { (void *)0x00000000L };
			struct string		oscript = { 0 };
			int					is_signed;
			unsigned char		hash_type;

			ret=get_tx_output					(&prev_tx, et[8], &prevout);
		
			tree_manager_get_child_value_istr	(&prevout, calc_crc32_c("script"), &oscript, 0);
			tree_manager_get_child_value_istr	(input, calc_crc32_c("script"), &script, 0);
			
			if (get_insig_info(&script, &sign, &vpubK, &hash_type))
			{
				if (vpubK.len == 0)
				{
					free_string(&vpubK);
					is_signed = get_out_script_address(&oscript, &vpubK, addr);

					if (!is_signed)log_output("unable to parse input addr \n");
				}
				else
				{
					is_signed = check_txout_key(&prevout, (unsigned char *)vpubK.str, addr);
					if (!is_signed)log_output("check input pkey hash failed\n");
				}

				if (is_signed)
				{
					hash_t txh;

					is_signed = compute_tx_sign_hash(tx, iidx, &oscript, hash_type, txh);
					if (is_signed)is_signed = check_sign(&sign, &vpubK, txh);
				}
				tree_manager_set_child_value_btcaddr(input, "srcaddr", addr);
			}
			else
			{
				is_signed = 0;

				if (get_out_script_address(&oscript, (void *)0x00000000L, addr))
					tree_manager_set_child_value_btcaddr(input, "srcaddr", addr);
			}

			tree_manager_set_child_value_bool(tx   , "pObjSigned", is_signed);
			tree_manager_set_child_value_i64 (input, "value", amount);

						
			free_string(&vpubK);
			free_string(&sign);
			free_string(&script);
			free_string(&oscript);

			if (ret)
			{
				unsigned int		type_id;
				uint64_t			val;

				tree_manager_get_child_value_i64(&prevout, calc_crc32_c("value"), &val);
				type_id = val & 0xFFFFFFFF;


				tree_manager_set_child_value_i32	(tx, "pObjType"		, type_id);
				tree_manager_set_child_value_vstr	(tx, "appChild"		, &appName);
				tree_manager_set_child_value_hash	(tx, "appChildOf"	, et);
				tree_manager_set_child_value_vstr	(input, "srcapp"	, &appName);
			}
					
			release_zone_ref					(&prevout);
			release_zone_ref					(&prev_tx);
			free_string							(&appName);
		}
		else if (prev_tx.zone != (void *)0x00000000L)
		{
			char			phash[65];
			mem_zone_ref	prevout = { (void *)0x00000000L }, txouts = { (void *)0x00000000L };
			unsigned char	*pet = (unsigned char *)et;
			
			n = 0;
			while (n < 32)
			{
				phash[n * 2 + 0] = hex_chars[pet[n] >> 0x04];
				phash[n * 2 + 1] = hex_chars[pet[n] & 0x0F];
				n++;
			}
			phash[64]	= 0;

			ret			= check_utxo(phash, et[8]);

			if (!ret)
			{
				char	rphash[65];
				char	iStr[16];

				n = 0;
				while (n < 32)
				{
					rphash[n * 2 + 0] = hex_chars[pet[31 - n] >> 0x04];
					rphash[n * 2 + 1] = hex_chars[pet[31 - n] & 0x0F];
					n++;
				}

				rphash[64] = 0;
				
				uitoa_s		(et[8], iStr, 16, 10);

				log_output	("bad utxo '");
				log_output	(rphash);
				log_output	("' - ");
				log_output	(iStr);
				log_output	("\n");

				







			}
		
			if ((ret)&&(get_tx_output(&prev_tx, et[8], &prevout)))
			{
				struct string	oscript = { (void *)0x00000000L }, script = { (void *)0x00000000L }, sign = { (void *)0x00000000L }, sigseq = { (void *)0x00000000L }, vpubK = { (void *)0x00000000L };
				mem_zone_ref	txTmp = { (void *)0x00000000L };
				size_t			offset = 0;
				unsigned char	hash_type;

				tree_manager_get_child_value_i64(&prevout, calc_crc32_c("value"), &amount);
				
				if ((amount & 0xFFFFFFFF00000000) == 0xFFFFFFFF00000000)
					amount = 0;


				tree_manager_get_child_value_istr	(&prevout, calc_crc32_c("script"), &oscript, 0);
				tree_manager_get_child_value_istr	(input, calc_crc32_c("script"), &script, 0);
				ret = get_insig_info				(&script, &sign, &vpubK, &hash_type);
				if (ret)
				{
					btc_addr_t addr;

					if (vpubK.len == 0)
					{
						free_string						(&vpubK);
						ret = get_out_script_address	(&oscript, &vpubK, addr);

						if (!ret)log_output("unable to parse input addr \n");
					}
					else
					{
						ret = check_txout_key(&prevout, (unsigned char *)vpubK.str, addr);
						if (!ret)log_output("check input pkey hash failed\n");
					}
					
					if (ret)
					{
						if (check_sig & 1)
						{
							hash_t txh;

							ret = compute_tx_sign_hash(tx, iidx, &oscript, hash_type, txh);
							if (ret)ret = check_sign(&sign, &vpubK, txh);
						}
					}

					if (ret)tree_manager_set_child_value_btcaddr(input, "srcaddr", addr);
					if (ret)tree_manager_set_child_value_i64	(input, "value", amount);
					
					free_string	(&vpubK);
					free_string	(&sign);
				}

				free_string		(&script);
				free_string		(&oscript);
				release_zone_ref(&prevout);

				if ((ret) && (check_sig & 2))
				{
					if (!bt_insert(&blk_root, et))
					{
						release_zone_ref(&prev_tx);
						release_zone_ref(&my_list);
						dec_zone_ref(input);
						release_zone_ref(&txin_list);
						log_output("double spent found \n");
						return 0;
					}
				}
			}
			release_zone_ref(&prev_tx);
		}

		if (!ret)
		{
			char prevTx[65];
			char iStr[16];
			unsigned char	*pet = (unsigned char *)et;

			n = 0;
			while (n < 32)
			{
				prevTx[n * 2 + 0] = hex_chars[pet[31 - n] >> 0x04];
				prevTx[n * 2 + 1] = hex_chars[pet[31 - n] & 0x0F];
				n++;
			}
			prevTx[64] = 0;

			itoa_s			(iidx, iStr, 16, 10);
			log_output		("check input failed at input #");
			log_output		(iStr);
			log_output		(" tx :'");
			log_output		(prevTx);
			log_output		("'\n");

			release_zone_ref	(&my_list);
			dec_zone_ref		(input);
			release_zone_ref	(&txin_list);
			return 0;
		}
		(*total_in) += amount;
	}
	release_zone_ref(&txin_list);
	return 1;
}




__declspec(dllexport) int  check_tx_outputs(mem_zone_ref_ptr tx, uint64_t *total, unsigned int *is_staking)
{
	mem_zone_ref		txout_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	out = (void *)0x00000000L;
	unsigned int		idx, app_flags, ret;

	*is_staking = 0;
	app_flags = 0;
	if (!tree_manager_find_child_node(tx, calc_crc32_c("txsout"), 0x0B080000, &txout_list))
	{
		log_output("no utxo\n");
		return 0;
	}
	for (idx = 0, tree_manager_get_first_child(&txout_list, &my_list, &out); ((out != (void *)0x00000000) && (out->zone != (void *)0x00000000)); idx++, tree_manager_get_next_child(&my_list, &out))
	{
		hash_t			pObjH;
		struct			string script = { 0 };
		uint64_t		amount = 0;
		unsigned int	app_item;

		ret = 1;

		if (!tree_manager_get_child_value_i64(out, calc_crc32_c("value"), &amount))continue;
		if (!tree_manager_get_child_value_istr(out, calc_crc32_c("script"), &script, 16))continue;

		if ((idx == 0) && (amount == 0) && (script.str[0] == 0))
		{
			*is_staking = 1;
		}
		else
		{
			btc_addr_t		addr;
			struct string	pubk = { (void *)0x00000000L };

			if (get_out_script_address(&script, &pubk, addr))
			{
				tree_manager_set_child_value_btcaddr(out, "dstaddr", addr);
				free_string(&pubk);
			}

			if (tree_manager_find_child_node(tx, calc_crc32_c("AppName"), 0x00000001, (void *)0x00000000L))
			{
				struct string my_val = { (void *)0x00000000L };
				if (get_out_script_return_val(&script, &my_val))
				{
					ret = (my_val.len == 1) ? 1 : 0;
					if (ret)
					{
						unsigned char app_code = *((unsigned char*)(my_val.str));
						switch (app_code)
						{
						case 1:app_flags |= 1; break;
						case 2:app_flags |= 2; break;
						case 3:app_flags |= 4; break;
						case 4:app_flags |= 8; break;
						case 5:app_flags |= 16; break;
						default:ret = 0; break;
						}
					}
					free_string(&my_val);
				}
				else if (!memcmp_c(addr, root_app_addr, sizeof(btc_addr_t)))
				{
					uint64_t root_amnt;
					if (!tree_manager_get_child_value_i64(tx, calc_crc32_c("app_root_amnt"), &root_amnt))root_amnt = 0;
					root_amnt += amount;
					tree_manager_set_child_value_i64(tx, "app_root_amnt", root_amnt);
				}
			}
			else if (tree_manager_get_child_value_i32(tx, calc_crc32_c("app_item"), &app_item))
			{
				switch (app_item)
				{
					case 1:
						if (amount == 0)
						{
							char			typeName[32];
							unsigned int	TypeId, flags;
							ret = get_type_infos(&script, typeName, &TypeId,&flags);
						}
					break;
					case 2:
						if ((amount & 0xFFFFFFFF00000000) == 0xFFFFFFFF00000000)
						{
							char			app_name[32];
							hash_t			sh;
							struct string	bsign = { 0 }, pkey = { 0 };
							unsigned int	type_id;

							type_id = amount & 0xFFFFFFFF;

							tree_manager_get_child_value_str (tx , calc_crc32_c("appObj"), app_name, 32, 0);
							tree_manager_get_child_value_istr(tx , calc_crc32_c("ObjSign"), &bsign,0);
							tree_manager_get_child_value_istr(out, calc_crc32_c("script"), &script, 0);

							get_out_script_address(&script, &pkey, addr);

							ret = (pkey.len == 33) ? 1 : 0;

							if (ret)ret = compute_tx_sign_hash(tx, 0, &script, 1, sh);
							if (ret)ret = check_sign(&bsign, &pkey, sh);

							free_string(&bsign);
							free_string(&pkey);
							
							if (ret)
							{
								mem_zone_ref types = { (void *)0x00000000L }, type = { (void *)0x00000000L }, myobj = { (void *)0x00000000L }, app = { (void *)0x00000000L };

								ret=tree_manager_find_child_node(&apps, calc_crc32_c(app_name), 0x0B008000, &app);

								if (ret)ret = get_app_types						(&app, &types);
								if (ret)ret = tree_find_child_node_by_id_name	(&types, 0x0B008000, "typeId", type_id, &type);
								if (ret)ret = obj_new							(&type, "objDef", &script, &myobj);
								if (ret)ret = check_app_obj_unique				(app_name,type_id,&myobj);
								if (ret)ret = tree_manager_node_add_child		(tx, &myobj);
								if (ret)ret = tree_manager_set_child_value_i32	(tx, "objType", type_id);

								release_zone_ref	(&myobj);
								release_zone_ref	(&type);
								release_zone_ref	(&types);
								release_zone_ref	(&app);

							}
							free_string(&script);
							amount = 0;
						}

					break;
					case 3:
						if (amount == 0xFFFFFFFFFFFFFFFF)
						{
							mem_zone_ref file = { (void *)0x00000000L };
							if (tree_manager_create_node("fileDef", 0x00000400, &file))
							{
								ret = get_script_file(&script, &file);
								if (ret)
								{
									hash_t h;
									tree_manager_get_child_value_hash	(&file, calc_crc32_c("dataHash"), h);
									tree_manager_set_child_value_hash	(tx, "fileHash", h);
									tree_manager_node_add_child			(tx, &file);
								}
								
								release_zone_ref(&file);
							}
							amount = 0;
						}
					break;
					case 4:
						if (amount == 0xFFFFFFFFFFFFFFFF)
						{
							mem_zone_ref file = { (void *)0x00000000L };
							if (tree_manager_create_node("layoutDef", 0x00000400, &file))
							{
								ret = get_script_layout(&script, &file);
								if (ret)tree_manager_node_add_child(tx, &file);
								release_zone_ref(&file);
							}
							amount = 0;
						}
					break;
					case 5:
						if (amount == 0xFFFFFFFFFFFFFFFF)
						{
							mem_zone_ref file = { (void *)0x00000000L };
							if (tree_manager_create_node("moduleDef", 0x00000400, &file))
							{
								ret = get_script_module(&script, &file);
								if (ret)tree_manager_node_add_child(tx, &file);
								release_zone_ref(&file);
							}
							amount = 0;
						}
					break;
				}
			}
			else if ((idx == 0) && (tree_manager_get_child_value_hash(tx, calc_crc32_c("appChildOf"), pObjH)))
			{
				size_t offset = 0;
				struct string key = { 0 }, cHash = { 0 };
				ret = get_script_data(&script, &offset, &key);
				if (ret)ret = get_script_data(&script, &offset, &cHash);
				if (ret)ret = (cHash.len == 32) ? 1 : 0;
				if (ret)
				{
					char			chash[65];
					struct string	appName;
					unsigned int	n, ptype, ktype, is_signed, flags;
					unsigned char	*hd = (unsigned char *)cHash.str;

					n = 0;
					while (n < 32)
					{
						chash[n * 2 + 0] = hex_chars[hd[n] >> 0x04];
						chash[n * 2 + 1] = hex_chars[hd[n] & 0x0F];
						n++;
					}
					chash[64] = 0;
					log_output("new obj child '");
					log_output(chash);
					log_output("':'");
					log_output(key.str);
					log_output("'\n");

					if (!tree_manager_get_child_value_i32(tx, calc_crc32_c("pObjSigned"), &is_signed))
						is_signed = 0;


					tree_manager_get_child_value_i32 (tx, calc_crc32_c("pObjType"), &ptype);
					tree_manager_get_child_value_istr(tx, calc_crc32_c("appChild"), &appName,0);

					ret=get_app_type_key				(appName.str,ptype, key.str, &ktype,&flags);
					
					if (ret)ret = ((ktype == 0x09000001) || (ktype == 0x09000002)) ? 1 : 0;
					if ((ret)&&((ktype == 0x09000001) && (!is_signed)))ret = 0;
					if (ret)
					{
						tree_manager_set_child_value_vstr(tx, "appChildKey", &key);
						tree_manager_set_child_value_hash(tx, "newChild", hd);
					}

					free_string(&appName);
				}
				free_string(&key);
				free_string(&cHash);
			}

			if (ret)*total += amount;
		}
		free_string(&script);
		if (!ret)
		{
			char iStr[16];
			itoa_s(idx, iStr, 16, 10);
			log_output("check output failed at output #");
			log_output(iStr);
			log_output("\n");
			dec_zone_ref(out);
			release_zone_ref(&my_list);
			break;
		}
	}
	release_zone_ref(&txout_list);

	if (!ret)return 0;

	if (tree_manager_find_child_node(tx, calc_crc32_c("AppName"), 0x00000001, (void *)0x00000000L))
	{
		if (app_flags != 31){
			log_output("invalid app tx\n");
			return 0;
		}
	}
	return 1;
}


__declspec(dllexport) int  find_inputs(mem_zone_ref_ptr tx_list, hash_t txid,unsigned int oidx)
{
	mem_zone_ref my_txlist = { (void *)0x00000000L };
	mem_zone_ref_ptr tx = (void *)0x00000000L;
	int ret=0;

	if (tx_list == (void *)0x00000000L)return 0;
	if (tx_list->zone == (void *)0x00000000L)return 0;

	for (tree_manager_get_first_child(tx_list, &my_txlist, &tx); ((tx != (void *)0x00000000L) && (tx->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_txlist, &tx))
	{
		mem_zone_ref		txin_list = { (void *)0x00000000L }, my_ilist = { (void *)0x00000000L };
		mem_zone_ref_ptr	input = (void *)0x00000000L;

		if (!tree_manager_find_child_node(tx, calc_crc32_c("txsin"), 0x0B010000, &txin_list))
			continue;

		for (tree_manager_get_first_child(&txin_list, &my_ilist, &input); ((input != (void *)0x00000000L) && (input->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_ilist, &input))
		{
			hash_t			th;
			unsigned int	idx;
			tree_manager_get_child_value_hash	(input, calc_crc32_c("txid"), th);
			tree_manager_get_child_value_i32	(input, calc_crc32_c("idx"), &idx);

			if (!memcmp_c(txid, th, sizeof(hash_t)) && (idx == oidx))
			{
				dec_zone_ref(input);
				release_zone_ref(&my_ilist);
				ret = 1;
				break;
			}
		}
		release_zone_ref(&txin_list);
		if (ret == 1)
		{
			dec_zone_ref(tx);
			release_zone_ref(&my_txlist);
			break;
		}
	}
	return ret;
}


__declspec(dllexport) int  check_tx_list(mem_zone_ref_ptr tx_list,uint64_t block_reward,hash_t merkle,unsigned int check_sig)
{
	hash_t				merkleRoot;
	mem_zone_ref		my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	tx = (void *)0x00000000L;
	uint64_t			list_reward;
	int					ret;
	unsigned int		coinbase, coinstaking, is_staking, is_coinbase;
	uint64_t			txFee, fees;

	build_merkel_tree	(tx_list, merkleRoot);

	if (memcmp_c(merkleRoot, merkle,sizeof(hash_t)))
	{
		log_message("bad merkle root ",(void *)0x00000000L);
		return 0;
	}
	tree_manager_get_first_child	(tx_list, &my_list, &tx);

	if (is_tx_null(tx))
	{
		tree_manager_get_next_child(&my_list, &tx);
		coinbase = 0;
		coinstaking = 1;
	}
	else
	{
		coinbase = 1;
		coinstaking = 0;
	}

	list_reward = 0;
	fees = 0;


	tree_manager_create_node("blkobjs", 0x0B004000, &blkobjs);
	
	bt_deltree(blk_root);

	blk_root = (void *)0x00000000L;

	ret = 1;
	for (; ((tx != (void *)0x00000000L) && (tx->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &tx))
	{
		struct string		tx_path = { 0 };
		uint64_t			total_in, total_out;
		mem_zone_ref		txin_list = { (void *)0x00000000L }, my_llist = { (void *)0x00000000L };
		mem_zone_ref_ptr	input = (void *)0x00000000L;

		is_staking = 0;
		is_coinbase = 0;
		total_out = 0;
		total_in = 0;

		if (is_tx_null(tx))
			continue;

		if(is_app_root(tx))
		{
			if(has_root_app)
			{
				log_output			("app root tx already set \n");
				dec_zone_ref		(tx);
				release_zone_ref	(&my_list);
				release_zone_ref	(&blkobjs);

				bt_deltree			(blk_root);
				return 0;
			}
			continue;
		}

		if (!check_tx_inputs(tx, &total_in, &is_coinbase, check_sig|2))
		{
			log_output("invalid inputs \n");
			dec_zone_ref		(tx);
			release_zone_ref	(&my_list);
			release_zone_ref	(&blkobjs);
			bt_deltree			(blk_root);
			return 0;
		}
		
		if (!check_tx_outputs(tx, &total_out, &is_staking))
		{
			log_output("invalid outputs \n");
			dec_zone_ref		(tx);
			release_zone_ref	(&my_list);
			release_zone_ref	(&blkobjs);
			bt_deltree			(blk_root);
			return 0;
		}
		
		if (is_staking)
		{
			if (coinstaking == 0)
			{
				log_output		("invalid coin stake \n");
				dec_zone_ref	(tx);
				release_zone_ref(&my_list);
				release_zone_ref	(&blkobjs);
				bt_deltree(blk_root);
				return 0;
			}
			coinstaking = 0;
			list_reward = total_out - total_in;
		}
		else if (is_coinbase)
		{
			if (coinbase == 0)
			{
				log_output("invalid coin base \n");

				dec_zone_ref		(tx);
				release_zone_ref	(&my_list);
				release_zone_ref	(&blkobjs);
				bt_deltree			(blk_root);
				return 0;
			}
			coinbase	= 0;
			list_reward = total_out - total_in;
		}
		else
		{
			if(total_out>total_in)
			{
				log_output("insufficient input \n");
				dec_zone_ref		(tx);
				release_zone_ref	(&my_list);
				release_zone_ref	(&blkobjs);
				bt_deltree			(blk_root);
				return 0;
			}
			
			txFee = total_in - total_out;
			fees += txFee;
		}
		if (tree_manager_find_child_node(tx, calc_crc32_c("AppName"), 0x00000001, (void *)0x00000000L))
		{
			uint64_t root_amnt;
			if (!tree_manager_get_child_value_i64(tx, calc_crc32_c("app_root_amnt"), &root_amnt))root_amnt = 0;

			if (root_amnt<app_fee)
			{
				log_output			("insufficient root amount\n");
				dec_zone_ref		(tx);
				release_zone_ref	(&my_list);
				release_zone_ref	(&blkobjs);
				bt_deltree			(blk_root);
				return 0;
			}
		}
	}
	
	
	release_zone_ref(&blkobjs);
	if (!ret)
	{
		log_message("error tx",(void *)0x00000000L);
		return 0;
	}
	if (list_reward > (block_reward + fees))
	{
		mem_zone_ref log = { (void *)0x00000000L };

		tree_manager_create_node		 ("log", 0x0A000010, &log);
		tree_manager_set_child_value_i64 (&log, "list", list_reward);
		tree_manager_set_child_value_i64 (&log, "block", block_reward);
		tree_manager_set_child_value_i64 (&log, "fees", fees);
		log_message						 ("bad tx reward %list% %block% %fees% ",&log);
		release_zone_ref				 (&log);
		return 0;
	}
	
	return 1;
}



__declspec(dllexport) int  check_block_pow(mem_zone_ref_ptr hdr,hash_t diff_hash)
{
	hash_t				blk_pow, rdiff;
	mem_zone_ref		log={(void *)0x00000000L};
	char				rpow[32];
	hash_t				bhash;
	int					n= 32;
	
	

	if (!tree_manager_get_child_value_hash(hdr, calc_crc32_c("blkHash"), bhash))
	{
		compute_block_hash					(hdr, bhash);
		tree_manager_set_child_value_bhash	(hdr, "blkHash", bhash);
	}
	if (!tree_manager_get_child_value_hash(hdr, calc_crc32_c("blk pow"), blk_pow))
	{
		compute_block_pow					(hdr, blk_pow);
		tree_manager_set_child_value_hash	(hdr, "blk pow", blk_pow);
	}
	n = 32;
	while (n--)
	{
		rdiff[n] = diff_hash[31 - n];
		rpow[n]  = blk_pow[31 - n];
	}
	
	if (cmp_hashle(blk_pow, rdiff) == 1)
	{
		tree_manager_create_node("log", 0x0A000010, &log);
		tree_manager_set_child_value_hash(&log, "diff", diff_hash);
		tree_manager_set_child_value_hash(&log, "pow", rpow);
		tree_manager_set_child_value_hash(&log, "hash", bhash);
		log_message("----------------\nNEW POW BLOCK\n%diff%\n%pow%\n%hash%\n", &log);
		release_zone_ref(&log);
		return 1;
	}
	else
	{
		tree_manager_create_node("log", 0x0A000010, &log);
		tree_manager_set_child_value_hash(&log, "diff", diff_hash);
		tree_manager_set_child_value_hash(&log, "pow" , rpow);
		tree_manager_set_child_value_hash(&log, "hash", bhash);
		log_message("----------------\nBAD POW BLOCK\n%diff%\n%pow%\n%hash%\n", &log);
		release_zone_ref(&log);
		return 0;
	}
	
}


__declspec(dllexport) int   get_prev_block_time(mem_zone_ref_ptr header, ctime_t *time)
{
	char prevHash[65];
	struct string blk_path = { 0 };
	
	if (!tree_manager_get_child_value_str(header, calc_crc32_c("prev"), prevHash,65,16))return 0;
	return get_block_time(prevHash, time);
}






__declspec(dllexport) int  block_has_pow(mem_zone_ref_ptr blockHash)
{
	char blk_hash[65];
	if (!tree_manager_get_node_str(blockHash, 0, blk_hash, 65, 16))return 0;
	return is_pow_block(blk_hash);
}
int make_iadix_merkle(mem_zone_ref_ptr genesis,mem_zone_ref_ptr txs,hash_t merkle)
{
	mem_zone_ref	newtx = { (void *)0x00000000L };
	mem_zone_ref	script_node = { (void *)0x00000000L };
	struct string	out_script = { (void *)0x00000000L }, script = { (void *)0x00000000L };
	struct string	timeproof = { (void *)0x00000000L };

	make_string(&timeproof, "1 Sep 2016 Iadix coin");
	tree_manager_create_node("script", 0x0B200000, &script_node);
	tree_manager_set_child_value_vint32(&script_node, "0", 0);
	tree_manager_set_child_value_vint32(&script_node, "1", 42);
	tree_manager_set_child_value_vstr(&script_node, "2", &timeproof);
	serialize_script		(&script_node, &script);
	release_zone_ref		(&script_node);

	new_transaction				(&newtx, 1466419086);
	tx_add_input				(&newtx, null_hash, 0xFFFFFFFF, &script);
	tx_add_output				(&newtx, 0, &out_script);
	free_string					(&script);
	free_string					(&timeproof);
	tree_manager_node_add_child (txs, &newtx);
	release_zone_ref			(&newtx);
	build_merkel_tree			(txs, merkle);
	
	return 0;
}


__declspec(dllexport) int  make_genesis_block(mem_zone_ref_ptr genesis_conf,mem_zone_ref_ptr genesis)
{
	hash_t								blk_pow, merkle;
	mem_zone_ref						txs = { (void *)0x00000000L };
	uint64_t							StakeMod;
	unsigned int						version, time, bits, nonce;
	hash_t								hmod;
	

	if (genesis->zone == (void *)0x00000000L)
	{
		if (!tree_manager_create_node("genesis", 0x0B000800, genesis))
			return 0;
	}
	
	if (!tree_manager_create_node("txs", 0x0B004000, &txs))
		return 0;
	
	if (!tree_manager_get_child_value_hash(genesis_conf, calc_crc32_c("merkle_root"), merkle))
	{
		make_iadix_merkle					(genesis, &txs, merkle);
	}
	
	tree_manager_set_child_value_hash	(genesis, "merkle_root"			, merkle);
	tree_manager_set_child_value_hash	(genesis, "prev"					, null_hash);

	tree_manager_get_child_value_i32	(genesis_conf, calc_crc32_c("version")	, &version);
	tree_manager_get_child_value_i32	(genesis_conf, calc_crc32_c("time")	, &time);
	tree_manager_get_child_value_i32	(genesis_conf, calc_crc32_c("bits")	, &bits);
	tree_manager_get_child_value_i32	(genesis_conf, calc_crc32_c("nonce")	, &nonce);


	tree_manager_set_child_value_i32	(genesis, "version"			, version);
	tree_manager_set_child_value_i32	(genesis, "time"			, time);
	tree_manager_set_child_value_i32	(genesis, "bits"			, bits);
	tree_manager_set_child_value_i32	(genesis, "nonce"			, nonce);
	
	tree_manager_node_add_child			(genesis, &txs);

	compute_block_pow					(genesis, blk_pow);
	tree_manager_set_child_value_bhash	(genesis, "blkHash", blk_pow);
	tree_manager_set_child_value_hash	(genesis, "blk pow" , blk_pow);
	
	if (tree_manager_get_child_value_i64(genesis_conf, calc_crc32_c("InitialStakeModifier"), &StakeMod))
		tree_manager_set_child_value_i64(genesis, "StakeMod", StakeMod);

	if (tree_manager_get_child_value_hash(genesis_conf, calc_crc32_c("InitialStakeModifier2"), hmod))
		tree_manager_set_child_value_hash(genesis, "StakeMod2", hmod);

	if (!find_hash(blk_pow))
	{
		store_block		(genesis, &txs);
	}
	release_zone_ref(&txs);
	return 1;

}


__declspec(dllexport) int  get_tx_data(mem_zone_ref_ptr tx, mem_zone_ref_ptr txData)
{
	struct string	txdata = { 0 };
	unsigned int	n;
	size_t			size;
	uint64_t		fee;
	unsigned char	*buffer;
	hash_t txh;

	tree_manager_get_child_value_i32(tx, calc_crc32_c("size"), &size);

	buffer = malloc_c(size);
	write_node(tx, buffer);

	txdata.len = size * 2;
	txdata.size = txdata.len + 1;
	txdata.str = malloc_c(txdata.size);

	for (n = 0; n < size; n++)
	{
		txdata.str[n * 2 + 0] = hex_chars[buffer[n] >> 4];
		txdata.str[n * 2 + 1] = hex_chars[buffer[n] & 0x0F];
	}
	txdata.str[txdata.len] = 0;

	free_c(buffer);

	if (!tree_manager_get_child_value_i64(tx, calc_crc32_c("fee"), &fee))
		fee = 0;
	tree_manager_get_child_value_hash	(tx, calc_crc32_c("txid"), txh);

	tree_manager_set_child_value_vstr	(txData, "data", &txdata);
	tree_manager_set_child_value_i64	(txData, "fee", fee);
	tree_manager_set_child_value_hash	(txData, "hash", txh);
	tree_manager_set_child_value_bool	(txData, "required", 1);

	free_string(&txdata);

	return 1;
}
