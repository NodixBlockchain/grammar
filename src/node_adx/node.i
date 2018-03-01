#line 1 "node.c"
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

#line 2 "node.c"
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



#line 3 "node.c"
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









#line 4 "node.c"
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

#line 5 "node.c"

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
#line 7 "node.c"
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

	
#line 147 "C:\\bitstream\\serv\\libbase\\include\\tree.h"





































































































































#line 8 "node.c"
#line 1 "C:\\bitstream\\serv\\libbase\\include\\http.h"






struct http_hdr
{
	char			key[64];
	enum op_type	op;
	struct string	value;
};

struct http_req
{
	struct string		error;
	struct string		req_line;
	struct key_val		req_headers[32];
	struct key_val		query_vars[32];
	unsigned char		*data;
	size_t				data_len;
};
struct http_infos
{
	struct string		method;
	struct string		path;
	struct string		query;
	struct string		http_version;
};

struct http_resp
{
	struct string		status_code;
	struct	key_val		resp_headers[32];
};





__declspec(dllimport) struct http_req  *		 new_http_req();
__declspec(dllimport) struct http_resp *		 new_http_resp();
__declspec(dllimport) struct http_req  *		 create_request(const struct host_def *host, const char *path, const struct string *data, int is_post, const struct string *cookie);
__declspec(dllimport) int						 http_make_request_header(struct http_req *req, struct string *header);
__declspec(dllimport) int						 http_make_response_header(const struct http_resp *resp, struct string *response);
__declspec(dllimport) int						 parse_http_req_line(const struct string *req_line, struct http_infos *infos);
__declspec(dllimport) void					 parse_http_query_vars(struct http_req *req, struct string *query);
__declspec(dllimport) int						 parse_query_line(const struct string *line, struct key_val *key);
__declspec(dllimport) int						 parse_http_url_params(const char *params, char sep, mem_zone_ref_ptr vars, unsigned int type);
__declspec(dllimport) int						 http_add_query_line(const struct string *line, struct key_val *hdrs);
__declspec(dllimport) void					 init_http_infos(struct http_infos *infos);
__declspec(dllimport) void					 free_http_infos(struct http_infos *infos);
__declspec(dllimport) char *					 http_add_header_line(const struct string *line, struct key_val *hdrs, char sep);
__declspec(dllimport) struct key_val *		 add_key(struct key_val *hdrs, const char *key, size_t key_len, const char *data, size_t data_len);
__declspec(dllimport) struct key_val *		 add_qkey(struct key_val *hdrs, const char *key, size_t key_len, const char *data, size_t data_len);
__declspec(dllimport) const struct key_val *	 find_key(const struct key_val *hdrs, const char *key);
__declspec(dllimport) void					 free_request(struct http_req *req);
__declspec(dllimport) void					 free_response(struct http_resp *resp);

__declspec(dllimport) struct http_resp *		 http_request(struct con *mycon, struct http_req *req, unsigned int n_tries, ctime_t timeout);
__declspec(dllimport) struct http_resp *		 http_parse_response_header(struct string *data);
__declspec(dllimport) void					 http_read_data(struct con *mycon, struct http_resp *resp, struct string *data);
__declspec(dllimport) struct  http_req*		 http_process_request(struct con *new_con, struct  http_infos	 *infos);
__declspec(dllimport) int						 fetch_http_url(const struct string *url, struct	string *data, const struct	string *cookie);
__declspec(dllimport) struct http_req *		 make_soap_request(const struct string *url, const char *soap_action, const char *soap_body, struct string *data);
__declspec(dllimport) int						 json_rpc(struct con *mycon, const char *method, mem_zone_ref_ptr params, unsigned int call_id, unsigned int mode);

__declspec(dllimport) int						 parse_multipart(const struct string *post_data, const struct string *boundary, mem_zone_ref_ptr form_parts);

#line 9 "node.c"
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
#line 10 "node.c"
#line 1 "C:\\bitstream\\serv\\libbase\\include\\parser.h"




__declspec(dllimport) int	 load_script				(const char *file,const char *name, mem_zone_ref_ptr script_vars,unsigned int opts);
__declspec(dllimport) int	 get_script_var_value_str (mem_zone_ref_ptr global_vars, const char *var_path, struct string *out, unsigned int radix);
__declspec(dllimport) int	 get_script_var_value_i32 (mem_zone_ref_ptr global_vars, const char *var_path, unsigned int *out);
__declspec(dllimport) int	 get_script_var_value_ptr	(mem_zone_ref_ptr global_vars, const char *var_path, mem_ptr *out);
__declspec(dllimport) int	 resolve_script_var(mem_zone_ref_ptr global_vars, mem_zone_ref_ptr script_proc, const char *var_path, unsigned int var_type, mem_zone_ref_ptr out_var, mem_zone_ref_ptr pout_var);
__declspec(dllimport) int	 execute_script_proc		(mem_zone_ref_ptr global_vars, mem_zone_ref_ptr script_proc);
__declspec(dllimport) int	 load_mod_def				(mem_zone_ref_ptr mod_def);

#line 11 "node.c"

#line 1 "C:\\bitstream\\serv\\libbase\\include\\crypto.h"


#line 4 "C:\\bitstream\\serv\\libbase\\include\\crypto.h"







typedef unsigned char dh_key_t[64];

typedef int				 crypto_extract_key_func	(dh_key_t pk, const dh_key_t sk);
typedef int 			 crypto_sign_open_func	(const struct string *sign, struct string *msg, const struct string *pk);

typedef crypto_sign_open_func	*crypto_sign_open_func_ptr;
typedef crypto_extract_key_func *crypto_extract_key_func_ptr;








#line 13 "node.c"
#line 1 "C:\\bitstream\\serv\\libbase\\include\\sha256.h"




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
#line 14 "node.c"
#line 1 "C:\\bitstream\\serv\\libcon\\include\\connect.h"
struct					con;




__declspec(dllimport) int					 network_init		();
__declspec(dllimport) int					 network_free();


__declspec(dllimport) int					 get_if(const char *gw_ip, struct string *name, struct string *ip);

__declspec(dllimport) void					 init_read_group();
__declspec(dllimport) int					 read_group_has(const char *file);

__declspec(dllimport) int					 set_tcp_no_delay(struct con *mycon, int on);
__declspec(dllimport) void					 add_read_group(struct con *mycon, void *file, size_t transfer_len, const struct string *file_name);

__declspec(dllimport) const struct string*	 get_con_error(struct con *Con);
__declspec(dllimport) struct string		*	 get_con_lastline(struct con *Con);
__declspec(dllimport) const struct host_def*	 get_con_hostd(struct con *Con);
__declspec(dllimport) int					 get_con_addr(struct con *mycon, char *addr, size_t len);
__declspec(dllimport) int					 get_con_saddr(struct con *mycon, ipv4_t saddr);
__declspec(dllimport) int					 get_con_ip(struct con *Con, ipv4_t ip);

__declspec(dllimport) int					 con_move_data(struct con *Con, struct string *data, size_t mov_len);
__declspec(dllimport) int					 con_consume_data(struct con *Con, size_t mov_len);


__declspec(dllimport) struct con *			 do_connect(const struct host_def *host);
__declspec(dllimport) struct con *			 create_upnp_broadcast(struct host_def *host);
__declspec(dllimport) int					 send_upnpbroadcast(struct con *mycon, struct string *msg);
__declspec(dllimport) int					 reconnect(struct con *mycon);
__declspec(dllimport) struct con *			 open_port(const char *my_addr, unsigned short port);
__declspec(dllimport) struct con *			 do_get_incoming(struct con *listen_con, unsigned int time_out);

__declspec(dllimport) int					 read_data(struct con *Con, size_t max);
__declspec(dllimport) int					 read_av_data(struct con *Con, size_t max);
__declspec(dllimport) int					 send_data(struct con *Con, unsigned char *data, size_t len);
__declspec(dllimport) int					 send_data_av(struct con *Con, unsigned char *data, size_t len);
__declspec(dllimport) char	*				 readline(struct con *Con, ctime_t timeout);

__declspec(dllimport) void					 do_read_group();
__declspec(dllimport) int					 pop_read_done(struct string *out);
__declspec(dllimport) void					 con_close(struct con *Con);

__declspec(dllimport) void					 free_con_buffer(struct con *my_con);
#line 15 "node.c"
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
#line 16 "node.c"
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

#line 17 "node.c"
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

#line 18 "node.c"
#line 1 "C:\\bitstream\\serv\\libbase\\include\\strbuffer.h"







typedef int (*get_func)(void *data);

typedef int64_t json_int_t;

typedef struct {
	char			value_ptr[1024];
    size_t length;   
    size_t size;     
} strbuffer_t;

typedef struct
{
    const char *data;
    size_t len;
    size_t pos;
} buffer_data_t;

typedef struct {
    get_func get;
    void *data;
    char buffer[5];
    size_t buffer_pos;
    int state;
    int line;
    int column, last_column;
    size_t position;
} stream_t;


typedef struct {
    stream_t	stream;
    strbuffer_t saved_text;
	char		value_buffer[1024];
    int			token;
    union {
        char		*string;
        json_int_t	integer;
        double		real;
    } value;
} lex_t;
















int strbuffer_init(strbuffer_t *strbuff);
void strbuffer_close(strbuffer_t *strbuff);

void strbuffer_clear(strbuffer_t *strbuff);

const char *strbuffer_value(const strbuffer_t *strbuff);


char *strbuffer_steal_value(strbuffer_t *strbuff);

int strbuffer_append(strbuffer_t *strbuff, const char *string);
int strbuffer_append_byte(strbuffer_t *strbuff, char byte);
int strbuffer_append_bytes(strbuffer_t *strbuff, const char *data, size_t size);

char strbuffer_pop(strbuffer_t *strbuff);

int  lex_init		(lex_t *lex,  void *data);
void lex_close		(lex_t *lex);
int  lex_scan		(lex_t *lex);
extern int  parse_value	(lex_t *lex,const char *name,unsigned int type,mem_zone_ref_ptr out);
void lex_steal_string(lex_t *lex, char *str, unsigned int str_len);


__declspec(dllimport) void  write_json(mem_zone_ref_ptr params, unsigned int mode, struct string *json_req);
#line 19 "node.c"
#line 1 "C:\\bitstream\\serv\\libbase\\include\\upnp.h"
struct pnpgw
{
	struct string	desc_url;
	struct string	control_path;
	struct string	control_url;
	struct string	desc;
	struct string	ex_ip;
};

__declspec(dllimport) int		 forwardPort			(struct string *port_str);
__declspec(dllimport) int		 broadcastDiscovery	();
__declspec(dllimport) void	 init_upnp			();
#line 20 "node.c"

#line 1 "c:\\bitstream\\serv\\node_adx\\../block_adx/block_api.h"


#line 4 "c:\\bitstream\\serv\\node_adx\\../block_adx/block_api.h"

struct bin_tree;
typedef struct bin_tree node;









__declspec(dllimport)  int	 init_blocks(mem_zone_ref_ptr node_config);


__declspec(dllimport)  void	 mul_compact(unsigned int nBits, uint64_t op, hash_t hash);


__declspec(dllimport)  int	 cmp_hashle(hash_t hash1, hash_t hash2);


__declspec(dllimport) unsigned int	 calc_new_target(unsigned int nActualSpacing, unsigned int TargetSpacing, unsigned int nTargetTimespan, unsigned int pBits);


__declspec(dllimport)  int	 get_block_height();


__declspec(dllimport)  int	 get_blockreward(uint64_t block, uint64_t *block_reward);


__declspec(dllimport)  int	 get_hash_list(mem_zone_ref_ptr hdr_list, mem_zone_ref_ptr hash_list);


__declspec(dllimport)  int	 build_merkel_tree(mem_zone_ref_ptr txs, hash_t merkleRoot);


__declspec(dllimport)  int	 make_genesis_block(mem_zone_ref_ptr genesis_conf, mem_zone_ref_ptr genesis_blk);


__declspec(dllimport) int	   get_tx_output(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr vout);


__declspec(dllimport)  int	   get_insig_info(const struct string *script, struct string *sign, struct string *pubk, unsigned char *hash_type);


__declspec(dllimport)  int	   parse_sig_seq(const struct string *sign_seq, struct string *sign, unsigned char *hashtype, int rev);


__declspec(dllimport)  int		serialize_script(mem_zone_ref_const_ptr script_node, struct string *script);


__declspec(dllimport)  int		create_null_tx(mem_zone_ref_ptr tx, unsigned int time, unsigned int block_height);


__declspec(dllimport)  int		is_tx_null(mem_zone_ref_const_ptr tx);


__declspec(dllimport)  int		is_vout_null(mem_zone_ref_const_ptr tx, unsigned int idx);


__declspec(dllimport)  int		new_transaction(mem_zone_ref_ptr tx, ctime_t time);


__declspec(dllimport)  int		 tx_add_output(mem_zone_ref_ptr tx, uint64_t value, const struct string *script);


__declspec(dllimport)  int		tx_add_input(mem_zone_ref_ptr tx, const hash_t tx_hash, unsigned int index,const struct string *script);


__declspec(dllimport)  int		create_payment_script(const struct string *pubk, unsigned int type, mem_zone_ref_ptr script_node);


__declspec(dllimport) int		create_payment_script_data(const struct string *pubk, unsigned int type, mem_zone_ref_ptr script_node, const unsigned char *data, size_t len);


__declspec(dllimport)  int		create_p2sh_script			(btc_addr_t addr, mem_zone_ref_ptr script_node);


__declspec(dllimport)  int		create_p2sh_script_byte		(btc_addr_t addr, mem_zone_ref_ptr script_node, unsigned char val);

__declspec(dllimport)  int		create_p2sh_script_data		(btc_addr_t addr, mem_zone_ref_ptr script_node, const unsigned char *data, size_t len);


__declspec(dllimport)  int		compute_tx_sign_hash		(mem_zone_ref_const_ptr tx, unsigned int nIn, const struct string *script, unsigned int hash_type, hash_t txh);


__declspec(dllimport)  int		check_tx_input_sig			(mem_zone_ref_const_ptr tx, unsigned int nIn, struct string *vpubK);


__declspec(dllimport)  int		check_tx_outputs			(mem_zone_ref_ptr tx, uint64_t *total, unsigned int *is_staking);


__declspec(dllimport)  int		check_tx_inputs				(mem_zone_ref_ptr tx, uint64_t *total_in, unsigned int *is_coinbase,unsigned int check_sig);



__declspec(dllimport)  int	 check_block_pow				(mem_zone_ref_ptr hdr, hash_t diff_hash);


__declspec(dllimport)  int	 check_block_sign				(const struct string *sign, const hash_t hash, const struct string *pubk);


__declspec(dllimport)  int	 get_tx_input_hash			(mem_zone_ref_ptr tx, unsigned int idx, hash_t hash);


__declspec(dllimport)  int	 get_tx_output_amount			(mem_zone_ref_ptr tx, unsigned int idx, uint64_t *amount);


__declspec(dllimport)  int	 get_tx_output_addr			(const hash_t tx_hash, unsigned int idx, btc_addr_t addr);


__declspec(dllimport)  int	 tx_sign						(mem_zone_ref_const_ptr tx, unsigned int nIn, unsigned int hashType, const struct string *sign, const struct string *inPubKey);


__declspec(dllimport) int		compute_block_hash			(mem_zone_ref_ptr block, hash_t hash);


__declspec(dllimport) int		compute_block_pow			(mem_zone_ref_ptr block, hash_t hash);


__declspec(dllimport)  int	 block_compute_pow_target		(mem_zone_ref_ptr ActualSpacing, mem_zone_ref_ptr diff);


__declspec(dllimport)  int	 compute_tx_hash				(mem_zone_ref_ptr tx, hash_t hash);


__declspec(dllimport) int		get_block_version			(unsigned int *v);


__declspec(dllimport) int		blk_check_sign				(const struct string *sign, const struct string *pubk, const hash_t hash);


__declspec(dllimport)  int	 check_tx_list				(mem_zone_ref_ptr tx_list, uint64_t block_reward,hash_t merkle,unsigned int check_sig);



__declspec(dllimport)  int	 find_inputs					(mem_zone_ref_ptr tx_list, hash_t txid, unsigned int oidx);


__declspec(dllimport) int		get_tx_input				(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr vin);



__declspec(dllimport) unsigned int	 SetCompact			(unsigned int bits, hash_t out);



__declspec(dllimport) int  check_utxo						(const char *tx, unsigned int oidx);


__declspec(dllimport) int  dump_tx_infos					(mem_zone_ref_ptr tx);
__declspec(dllimport) int  dump_txh_infos					(const char *hash);


__declspec(dllimport)  int	 get_block_tree				(node **blktree);

__declspec(dllimport)  int	 get_tx_data					(mem_zone_ref_ptr tx, mem_zone_ref_ptr txData);

__declspec(dllimport)  int	 blk_find_last_pow_block		(mem_zone_ref_ptr pindex, unsigned int *block_time);
__declspec(dllimport)  int	 block_pow					(uint64_t height);
__declspec(dllimport)  int	 extract_key					(dh_key_t priv, dh_key_t pub);
__declspec(dllimport)  int	 remove_tx_index				(hash_t tx_hash);

__declspec(dllimport) int  set_root_app					(mem_zone_ref_ptr tx);
__declspec(dllimport) int  get_root_app					(mem_zone_ref_ptr  rootAppHash);
__declspec(dllimport) int  get_apps						(mem_zone_ref_ptr Apps);

__declspec(dllimport) int  get_root_app_addr				(mem_zone_ref_ptr rootAppAddr);

__declspec(dllimport) int  is_app_root					(mem_zone_ref_ptr tx);

__declspec(dllimport) int  blk_load_app_root				();

__declspec(dllimport) int  blk_load_apps					(mem_zone_ref_ptr apps);

__declspec(dllimport) int  make_approot_tx				(mem_zone_ref_ptr tx, ctime_t time,btc_addr_t addr);

__declspec(dllimport) int  get_root_app_fee				(mem_zone_ref_ptr rootAppFees);

__declspec(dllimport) int  make_app_tx					(mem_zone_ref_ptr tx,const char *app_name,btc_addr_t appAddr);
__declspec(dllimport) int  make_app_item_tx				(mem_zone_ref_ptr tx, const struct string *app_name, unsigned int item_id);
__declspec(dllimport) int  parse_approot_tx				(mem_zone_ref_ptr tx);


__declspec(dllimport)  int   get_app_name					(const struct string *script, struct string *app_name);
__declspec(dllimport)  int   get_app_types				(mem_zone_ref_ptr app, mem_zone_ref_ptr types);
__declspec(dllimport)  int   get_app_scripts				(mem_zone_ref_ptr app, mem_zone_ref_ptr scripts);

__declspec(dllimport)  int	 get_type_infos				(struct string *script, char *name, unsigned int *id, unsigned int *flags);

__declspec(dllimport)  int	 get_tx_file					(mem_zone_ref_ptr tx, mem_zone_ref_ptr hash_list);
__declspec(dllimport)  int	 tx_is_app_file				(mem_zone_ref_ptr tx, struct string *appName, mem_zone_ref_ptr file);
__declspec(dllimport)  int	 get_app_type_key				(const char *appName, unsigned int type_id, const char *kname, unsigned int *ktype, unsigned int *flags);
__declspec(dllimport)  int	 get_app_type_idxs			(const char *appName, unsigned int type_id, mem_zone_ref_ptr keys);
__declspec(dllimport)  int	 load_obj_type				(const char *app_name, const char *objHash, unsigned int *type_id, btc_addr_t objAddr);
__declspec(dllimport)  int	 check_app_obj_unique			(const char *appName, unsigned int type_id, mem_zone_ref_ptr obj);









__declspec(dllimport) int    get_out_script_address(const struct string *script, struct string *pubk, btc_addr_t addr);


__declspec(dllimport) int    get_out_script_return_val(const struct string *script, struct string *data);


__declspec(dllimport) int    get_tx_output_script(const hash_t tx_hash, unsigned int idx, struct string *script, uint64_t *amount);


__declspec(dllimport) void    key_to_hash(const unsigned char *pkey, unsigned char *keyHash);


__declspec(dllimport) void   key_to_addr(const unsigned char *pkey, btc_addr_t addr);


__declspec(dllimport) void    paddr_to_key(btc_paddr_t addr, dh_key_t key);


__declspec(dllimport) int    make_script_file(mem_zone_ref_ptr file, struct string *pKey, struct string *sign, mem_zone_ref_ptr script);

__declspec(dllimport) int    make_script_layout(mem_zone_ref_ptr file, mem_zone_ref_ptr script);

__declspec(dllimport) int    make_script_module(mem_zone_ref_ptr file, mem_zone_ref_ptr script);






__declspec(dllimport) int   get_moneysupply(uint64_t *amount);


__declspec(dllimport) int  get_last_block_height();


__declspec(dllimport) int   find_blk_hash(const hash_t tx_hash, hash_t blk_hash,uint64_t *height,unsigned int *ofset,unsigned int *tx_time);


__declspec(dllimport) int   find_hash(hash_t hash);


__declspec(dllimport) int   find_index_hash(hash_t h);


__declspec(dllimport) int   load_blk_hdr(mem_zone_ref_ptr hdr, const char *blk_hash);


__declspec(dllimport) int   get_blk_height(const char *blk_hash, uint64_t *height);


__declspec(dllimport) int   get_tx_blk_height(const hash_t tx_hash, uint64_t *height, uint64_t *block_time, unsigned int *tx_time);


__declspec(dllimport) int   is_pow_block(const char *blk_hash);


__declspec(dllimport) int   store_block(mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list);


__declspec(dllimport) int   blk_load_tx_ofset(const char *blk_hash, unsigned int ofset, mem_zone_ref_ptr tx);


__declspec(dllimport) int   load_tx(mem_zone_ref_ptr tx, hash_t blk_hash, const hash_t tx_hash);


__declspec(dllimport) int   load_tx_input(mem_zone_ref_const_ptr tx, unsigned int idx, mem_zone_ref_ptr	vin, mem_zone_ref_ptr tx_out);


__declspec(dllimport) int   load_blk_tx_input(const char *blk_hash, unsigned int tx_ofset, unsigned int vin_idx, mem_zone_ref_ptr vout);


__declspec(dllimport) int   load_tx_output_amount(const hash_t tx_hash, unsigned int idx, uint64_t *amount);


__declspec(dllimport) int   load_tx_input_vout(mem_zone_ref_const_ptr tx, unsigned int vin_idx, mem_zone_ref_ptr vout);


__declspec(dllimport) int   load_tx_addresses(btc_addr_t addr, mem_zone_ref_ptr tx_hashes);


__declspec(dllimport) int   load_obj(const char *app_name, const char *objHash, const char *objName, unsigned int opts, mem_zone_ref_ptr obj, btc_addr_t objAddr);


__declspec(dllimport) int   load_obj_childs(const char *app_name, const char *objHash, const char *KeyName, size_t first, size_t max, unsigned int opts, mem_zone_ref_ptr objs);


__declspec(dllimport) int   make_app_child_obj_tx(mem_zone_ref_ptr tx, const char *app_name, hash_t objHash, const char *keyName, unsigned int ktype,hash_t childHash);


__declspec(dllimport) int   get_app_obj_hashes(const char *app_name, mem_zone_ref_ptr hash_list);


__declspec(dllexport) int  get_app_type_last_objs_hashes(const char *app_name, unsigned int type_id, size_t first, size_t max, mem_zone_ref_ptr hash_list);


__declspec(dllimport) int   get_block_size(const char *blk_hash, size_t *size);


__declspec(dllimport) int   get_blk_tx_hash(const char* blk_hash, unsigned int idx, hash_t tx_hash);


__declspec(dllimport) int   get_blk_txs(const char* blk_hash, mem_zone_ref_ptr txs, size_t max);


__declspec(dllimport) unsigned int   get_blk_ntxs(const char* blk_hash);


__declspec(dllimport) int   load_blk_txs(const char* blk_hash, mem_zone_ref_ptr txs);


__declspec(dllimport) int   get_block_time(const char *blkHash, ctime_t *time);


__declspec(dllimport) int   store_tx_inputs(mem_zone_ref_ptr tx);


__declspec(dllimport) int   store_tx_outputs(mem_zone_ref_ptr tx);


__declspec(dllimport) int   store_tx_addresses(btc_addr_t addr, hash_t tx_hash);


__declspec(dllimport) int   remove_tx_addresses(const btc_addr_t addr, const hash_t tx_hash);


__declspec(dllimport) int   remove_tx(hash_t tx_hash);


__declspec(dllimport)  int	 load_block_indexes(mem_zone_ref_ptr hdr_list);


__declspec(dllimport)  int	 store_tx_blk_index(const hash_t tx_hash, const hash_t blk_hash,uint64_t height,size_t tx_ofset,unsigned int time);


__declspec(dllimport) int   store_block_txs(mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list);


__declspec(dllimport)  int	 clear_tx_index();


__declspec(dllimport)  int	 get_app_type_obj_hashes(const char *app_name, unsigned int type_id, size_t first, size_t max, mem_zone_ref_ptr hash_list);
__declspec(dllimport)  int	 get_app_type_nobjs(const char *app_name, unsigned int type_id);
__declspec(dllimport)  int	 get_app_file(mem_zone_ref_ptr file_tx, struct string *app_name, mem_zone_ref_ptr file);
__declspec(dllimport)  int	 get_appfile_tx(const char *app_name, hash_t fileHash, hash_t txHash);
__declspec(dllimport)  int	 has_app_file(struct string *app_name, hash_t fileHash);
__declspec(dllimport)  int	 get_app_files(struct string *app_name, size_t first, size_t num, mem_zone_ref_ptr files);
__declspec(dllimport)  int	 get_app_missing_files(struct string *app_name, mem_zone_ref_ptr pending, mem_zone_ref_ptr files);





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
#line 22 "node.c"
#line 1 "c:\\bitstream\\serv\\node_adx\\../wallet/wallet_api.h"

	
#line 4 "c:\\bitstream\\serv\\node_adx\\../wallet/wallet_api.h"



__declspec(dllimport) int  init_wallet(mem_zone_ref_ptr node, tpo_mod_file *pos_mod);
__declspec(dllimport) int  find_stake_hash(hash_t hash, unsigned char *stakes, unsigned int len);
__declspec(dllimport) int  get_tx_inputs_from_addr(btc_addr_t addr, mem_zone_ref_ptr mempool, uint64_t *total_unspent, uint64_t min_amount, size_t min_conf, size_t max_conf, mem_zone_ref_ptr tx);
__declspec(dllimport) int  list_received	(btc_addr_t addr, mem_zone_ref_ptr received, size_t min_conf, size_t max_conf, uint64_t *amount, size_t *ntx, size_t *max, size_t first);
__declspec(dllimport) int  list_unspent	(btc_addr_t addr, mem_zone_ref_ptr unspents, mem_zone_ref_ptr mempool, size_t min_conf, size_t max_conf, uint64_t *total_unspent, size_t *ntx, size_t *max, size_t first);
__declspec(dllimport) int  list_spent	(btc_addr_t addr, mem_zone_ref_ptr spents, size_t min_conf, size_t max_conf, uint64_t *total_spent, size_t *ntx, size_t *max, size_t first);
__declspec(dllimport) int  get_balance(btc_addr_t addr, uint64_t *conf_amount, uint64_t *amount, unsigned int minconf);
__declspec(dllimport) int  remove_wallet_tx(const hash_t tx_hash);
__declspec(dllimport) int  add_unspent(btc_addr_t	addr, const char *tx_hash, unsigned int oidx, uint64_t amount, btc_addr_t *src_addrs, unsigned int n_addrs);
__declspec(dllimport) int  spend_tx_addr(btc_addr_t addr, const char *tx_hash, unsigned int vin, const char *ptx_hash, unsigned int oidx, btc_addr_t *addrs_to, unsigned int n_addrs_to);
__declspec(dllimport) int  store_tx_wallet(btc_addr_t addr, hash_t tx_hash);
__declspec(dllimport) int  store_wallet_tx(mem_zone_ref_ptr tx);
__declspec(dllimport) int  store_wallet_txs(mem_zone_ref_ptr tx_list);
__declspec(dllimport) int  list_staking_unspent(mem_zone_ref_ptr last_blk, btc_addr_t addr, mem_zone_ref_ptr mempool, mem_zone_ref_ptr unspents, unsigned int min_depth, int *max);
__declspec(dllimport) int  wallet_list_addrs(mem_zone_ref_ptr account_name, mem_zone_ref_ptr addr_list);
__declspec(dllimport) int  setpassword(struct string *username, struct string *pw, struct string *newpw);
__declspec(dllimport) int  checkpassword(struct string *username, struct string *pw);
__declspec(dllimport) int  uname_cleanup(struct string *uname);
__declspec(dllimport) int  add_keypair(struct string *username, const char *clabel, btc_addr_t pubaddr, dh_key_t priv, unsigned int rescan, unsigned int *found);
__declspec(dllimport) int  get_privkey(struct string *username, struct string *pubaddr, dh_key_t key);
__declspec(dllimport) int  get_account_list(mem_zone_ref_ptr accnt_list,unsigned int page_idx);


__declspec(dllimport) int  set_anon_pw(const char *pw, unsigned int timeout);
__declspec(dllimport) int  generate_new_keypair(const char *clabel, btc_addr_t pubaddr);
#line 23 "node.c"


#line 1 "c:\\bitstream\\serv\\node_adx\\node_api.h"




__declspec(dllexport) int					node_init_self(mem_zone_ref_ptr self_node);
__declspec(dllexport) int					node_set_last_block(mem_zone_ref_ptr header);
__declspec(dllexport) int					node_load_last_blks();
__declspec(dllexport) int					node_log_addr_infos(mem_zone_ref_ptr addr);
__declspec(dllexport) int					update_peernodes();
__declspec(dllexport) int					node_add_block_index(hash_t hash, unsigned int time);
__declspec(dllexport) int					node_add_tx_to_mempool(mem_zone_ref_ptr tx);
__declspec(dllexport) int					node_get_mempool_hashes(mem_zone_ref_ptr hash_list);
__declspec(dllexport) int					node_fill_block_from_mempool(mem_zone_ref_ptr block);
__declspec(dllexport) int					node_txsdata_from_mempool(mem_zone_ref_ptr tx_list, mem_zone_ref_ptr Fees);
__declspec(dllexport) int					node_del_txs_from_mempool(mem_zone_ref_ptr tx_list);
__declspec(dllexport) int					node_del_btree_from_mempool();
__declspec(dllexport) int					node_get_hash_idx(uint64_t block_idx, hash_t hash);
__declspec(dllexport) int					node_get_last_block_time(ctime_t *otime);
__declspec(dllexport) int					node_truncate_chain(uint64_t height);
__declspec(dllexport) int					node_remove_last_block();
__declspec(dllexport) int					node_rewrite_txs(uint64_t nums);
__declspec(dllexport) int					node_check_chain(mem_zone_ref_ptr node, mem_zone_ref_ptr hdr);
__declspec(dllexport) int					node_zip_self(struct string *out_data, mem_zone_ref_ptr opts);
__declspec(dllexport) int				    node_get_script_modules(mem_zone_ref_ptr modules);
__declspec(dllexport) int				    node_get_script_msg_handlers(mem_zone_ref_ptr handlers);
__declspec(dllexport) int					node_set_script(mem_zone_ref_ptr script);
__declspec(dllexport) int					remove_block(hash_t blk_hash);
__declspec(dllexport) int					node_list_accounts(mem_zone_ref_ptr account_list);
__declspec(dllexport) int					node_list_addrs(mem_zone_ref_ptr account_name, mem_zone_ref_ptr addr_list);
__declspec(dllexport) int					set_next_check(mem_zone_ref_ptr nSecs);
__declspec(dllexport) int					node_check_new_connections();
__declspec(dllexport) int					node_get_pow_spacing(mem_zone_ref_ptr lastPOW, mem_zone_ref_ptr Spacing);
__declspec(dllexport) int					compute_last_pow_diff(mem_zone_ref_ptr blk, mem_zone_ref_ptr nBits);

__declspec(dllexport) int					node_store_last_pow_hash(mem_zone_ref_ptr blk);
__declspec(dllexport) int					node_store_last_pos_hash(mem_zone_ref_ptr blk);


__declspec(dllexport) int					node_dump_memory(unsigned int flags);
__declspec(dllexport) int					node_init_service(mem_zone_ref_ptr service, mem_zone_ref_ptr pos_mod_def);

__declspec(dllexport) int					get_file_mime(mem_zone_ref_const_ptr service, const char *filepath, struct string *mime);
__declspec(dllexport) int					check_http_request(mem_zone_ref_const_ptr service);
__declspec(dllexport) int					node_init_service(mem_zone_ref_ptr service, mem_zone_ref_ptr pos_mod_def);
__declspec(dllexport) int					node_process_event_handler(const char *msg_list_name, mem_zone_ref_ptr node, mem_zone_ref_ptr msg);

__declspec(dllexport) int					node_is_next_block(mem_zone_ref_const_ptr header);
__declspec(dllexport) int					connect_peer_node(mem_zone_ref_ptr node_def);
__declspec(dllexport) int					read_node_msg(mem_zone_ref_ptr node);
__declspec(dllexport) int					send_node_messages(mem_zone_ref_ptr node);
__declspec(dllexport) int					node_add_block_header(mem_zone_ref_ptr node, mem_zone_ref_ptr hdr);
__declspec(dllexport) int					queue_version_message(mem_zone_ref_ptr node);
__declspec(dllexport) int					queue_verack_message(mem_zone_ref_ptr node);
__declspec(dllexport) int					queue_ping_message(mem_zone_ref_ptr node);
__declspec(dllexport) int					queue_pong_message(mem_zone_ref_ptr node, mem_zone_ref_ptr nonce);
__declspec(dllexport) int					queue_getaddr_message(mem_zone_ref_ptr node);
__declspec(dllexport) int					queue_getdata_message(mem_zone_ref_ptr node, mem_zone_ref_ptr hash_list);
__declspec(dllexport) int					get_locator_next_blocks(mem_zone_ref_ptr locator, mem_zone_ref_ptr inv_pack);

__declspec(dllexport) int					queue_block_message(mem_zone_ref_ptr node, mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list, struct string *signature);
__declspec(dllexport) int					queue_tx_message(mem_zone_ref_ptr node, mem_zone_ref_ptr tx);
__declspec(dllexport) int					queue_getblocks_message(mem_zone_ref_ptr node);
__declspec(dllexport) int					queue_getblock_hdrs_message(mem_zone_ref_ptr node);
__declspec(dllexport) int					queue_send_message(mem_zone_ref_ptr node, mem_zone_ref_ptr msg);
__declspec(dllexport) int					queue_emitted_element(mem_zone_ref_ptr node, mem_zone_ref_ptr element);
__declspec(dllexport) int					queue_emitted_message(mem_zone_ref_ptr node, mem_zone_ref_ptr msg);
__declspec(dllexport) int					queue_inv_message(mem_zone_ref_ptr node, mem_zone_ref_ptr hash_list);
__declspec(dllexport) int					queue_addr_message(mem_zone_ref_ptr node, mem_zone_ref_ptr addrs);

__declspec(dllexport) int					node_check_services();
__declspec(dllexport) int					reset_moneysupply();
__declspec(dllexport) int					add_moneysupply(uint64_t amount);
__declspec(dllexport) int					sub_moneysupply(uint64_t amount);
__declspec(dllexport) int					node_has_block(mem_zone_ref_ptr hash);
__declspec(dllexport) int					node_mempool_has_tx(mem_zone_ref_ptr tx_hash);
__declspec(dllexport) int					node_create_pow_block(mem_zone_ref_ptr newBlock,btc_addr_t addr);



__declspec(dllexport) int					 node_get_root_app_fee(mem_zone_ref_ptr fee);
__declspec(dllexport) int					 node_get_apps(mem_zone_ref_ptr apps);
__declspec(dllexport) int					 node_get_app(mem_zone_ref_ptr appName, mem_zone_ref_ptr app);
__declspec(dllexport) int					 node_get_types_def(mem_zone_ref_ptr types);
__declspec(dllexport) int					 node_store_tmp_file(struct string *app_name, mem_zone_ref_ptr file);
__declspec(dllexport) int					 node_rm_tmp_file(struct string *app_name, mem_zone_ref_ptr file);
__declspec(dllexport) int					 node_release_mining_lock();
__declspec(dllexport) int					 node_aquire_mining_lock();

__declspec(dllexport) int					 node_aquire_mempool_lock(mem_zone_ref_ptr mempool);
__declspec(dllexport) int					 node_release_mempool_lock();

#line 26 "node.c"




__declspec(dllimport) void					get_magic					(unsigned int *inmagic);
__declspec(dllimport) size_t					get_node_size				(mem_zone_ref_ptr key);
__declspec(dllimport) char*					serialize_message			(mem_zone_ref_ptr msg);
__declspec(dllimport) int					unserialize_message			(mem_zone_ref_ptr msg, mem_ptr payload, size_t len,const char *model);
__declspec(dllimport) void					init_protocol				(mem_zone_ref_ptr params);
__declspec(dllimport) int					new_message					(const struct string *data, mem_zone_ref_ptr msg);

__declspec(dllimport) const char*			init_node					(mem_zone_ref_ptr key);
__declspec(dllimport) size_t					read_node					(mem_zone_ref_ptr key, const char *payload, size_t len);
__declspec(dllimport) int					add_bitcore_addr			(mem_zone_ref_ptr node, ipv4_t ip, unsigned short port,unsigned int services);
__declspec(dllimport) int					create_version_message		(mem_zone_ref_ptr node, mem_zone_ref_ptr self_node, mem_zone_ref_ptr ver_pack);
__declspec(dllimport) int					create_verack_message		(mem_zone_ref_ptr node, mem_zone_ref_ptr ver_pack);
__declspec(dllimport) int					create_mempool_message		(mem_zone_ref_ptr node, mem_zone_ref_ptr mempool_pack);
__declspec(dllimport) int					create_pong_message			(mem_zone_ref_ptr node, uint64_t nonce, mem_zone_ref_ptr ver_pack);
__declspec(dllimport) int					create_ping_message			(mem_zone_ref_ptr node, uint64_t nonce, mem_zone_ref_ptr ver_pack);
__declspec(dllimport) int					create_getaddr_message		(mem_zone_ref_ptr node, mem_zone_ref_ptr addr_pack);
__declspec(dllimport) int					create_inv_message			(mem_zone_ref_ptr node, mem_zone_ref_ptr hash_list, mem_zone_ref_ptr inv_pack);
__declspec(dllimport) int					create_getdata_message		(mem_zone_ref_ptr node, mem_zone_ref_ptr hash_list, mem_zone_ref_ptr blk_hdr_pack);
__declspec(dllimport) int					create_getheaders_message	(mem_zone_ref_ptr node, unsigned int version, mem_zone_ref_ptr blk_locator, hash_t hash_stop, mem_zone_ref_ptr blk_hdr_pack);
__declspec(dllimport) int					create_getblocks_message	(mem_zone_ref_ptr node, unsigned int version,mem_zone_ref_ptr blk_locator, mem_zone_ref_ptr blk_hdr_pack);
__declspec(dllimport) int					create_block_message		(mem_zone_ref_ptr node, mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list, struct string *signature, mem_zone_ref_ptr block_pack);
__declspec(dllimport) int					create_tx_message			(mem_zone_ref_ptr node, mem_zone_ref_ptr tx, mem_zone_ref_ptr tx_pack);
__declspec(dllimport) int					create_file_message			(mem_zone_ref_ptr node, mem_zone_ref_ptr file, mem_zone_ref_ptr file_pack);
__declspec(dllimport) int					create_addr_message			(mem_zone_ref_ptr node, mem_zone_ref_ptr addrs, mem_zone_ref_ptr addr_pack);


__declspec(dllimport) char*					write_node(mem_zone_ref_const_ptr key, unsigned char *payload);

extern int				proccess_http_reqs(mem_zone_ref_ptr service);

unsigned int			last_msg_id = 1;
ctime_t					last_dump_time = 0xFFFFFFFF;
unsigned int			mining_lock = 0xFFFFFFFF;
unsigned int			mempool_lock = 0xFFFFFFFF;
mem_zone_ref			nself_node = { (void *)0xDEADBEEFLL };
mem_zone_ref			node_script = { (void *)0xDEADBEEFLL };

__declspec(dllexport) int  node_check_services()
{
	mem_zone_ref service = { (void *)0x00000000L };
	unsigned int nreqs = 0, nthreads = 0;

	while (tree_node_find_child_by_type(&nself_node, 0x08000100, &service, nreqs++))
	{
		check_http_request	(&service);

		if (!tree_manager_get_child_value_i32(&service,calc_crc32_c("nthreads"), &nthreads))
			nthreads = 0;

		if (nthreads == 0)
		{
			mem_zone_ref mods = { (void *)0x00000000L };

			if (tree_manager_find_child_node(&service, calc_crc32_c("modules"), 0x09000001, &mods))
			{
				proccess_http_reqs(&mods);
				release_zone_ref(&mods);
			}
		}

		release_zone_ref	(&service);

	}
	return 1;
}



__declspec(dllexport) int  remove_block(hash_t blk_hash)
{
	char			chash[65];
	struct string	blk_path = { 0 }, blk_data_path = { 0 };
	unsigned char	*txs;
	size_t			len;
	int				n;

	n = 0;
	while (n<32)
	{
		chash[n * 2 + 0] = hex_chars[blk_hash[n] >> 4];
		chash[n * 2 + 1] = hex_chars[blk_hash[n] & 0x0F];
		n++;
	}
	chash[64] = 0;



	make_string		(&blk_path, "blks");
	cat_ncstring_p	(&blk_path, chash + 0, 2);
	cat_ncstring_p	(&blk_path, chash + 2, 2);
	cat_cstring_p	(&blk_path, chash);
	cat_cstring		(&blk_path, "_txs");

	if(get_file		(blk_path.str,&txs,&len)>0)
	{
		size_t fofs	=	0;
		while((fofs+4)<len)
		{
			hash_t th,txh;
			size_t size	=	*((unsigned int *)(txs+fofs));

			if((fofs+4+size)>len)break;
			
			mbedtls_sha256(txs+fofs+4,size,th,0);
			mbedtls_sha256(th,txh,0);

			remove_wallet_tx(txh);
			remove_tx		(txh);
			
			fofs+=size+4;
		}
		free_c(txs);
		del_file(blk_path.str);
	}
	free_string(&blk_path);

	make_string		(&blk_path, "blks");
	cat_ncstring_p	(&blk_path, chash + 0, 2);
	cat_ncstring_p	(&blk_path, chash + 2, 2);
	cat_cstring_p	(&blk_path, chash);
	cat_cstring		(&blk_path, "_blk");

	if(get_file	(blk_path.str,&txs,&len)>0)
	{
		size_t fofs	=	238;
		while((fofs+32)<=len)
		{
			remove_wallet_tx(&txs[fofs]);
			remove_tx		(&txs[fofs]);
			fofs+=32;
		}
		free_c		(txs);
		del_file	(blk_path.str);
	}
	free_string	(&blk_path);

	return 1;
}


__declspec(dllexport) int  remove_stored_block(mem_zone_ref_ptr block)
{
	hash_t hash;
	if (!tree_manager_get_child_value_hash(block, calc_crc32_c("blkHash"), hash))
	{
		compute_block_hash					(block, hash);
		tree_manager_set_child_value_bhash	(block, "blkHash", hash);
	}
	if (!find_hash(hash))return 0;
	
	return remove_block(hash);
}


__declspec(dllexport) int  node_list_addrs(mem_zone_ref_ptr account_name,mem_zone_ref_ptr addr_list)
{

	tree_remove_children(addr_list);
	wallet_list_addrs	(account_name, addr_list);

	return 1;
}

__declspec(dllexport) int  node_list_accounts(mem_zone_ref_ptr accnt_list)
{
	mem_zone_ref	page_idx_n = { (void *)0x00000000L };
	struct string	user_list = { (void *)0x00000000L }, user_key_file = { (void *)0x00000000L };
	size_t			keys_data_len = 0;
	size_t			nfiles;
	unsigned char	*keys_data = (void *)0x00000000L;

	tree_remove_children(accnt_list);

	if ((nfiles = get_sub_files("keypairs", &user_list))>0)
	{
		size_t		dir_list_len;
		const char *ptr, *optr;
		size_t		cur;

		dir_list_len = user_list.len;
		optr = user_list.str;
		cur = 0;
		while (cur < nfiles)
		{
			struct string	user_name = { (void *)0x00000000L };
			mem_zone_ref	accnt = { (void *)0x00000000L };
			size_t			sz;
			char			*ustr;

			ptr = memchr_c(optr, 10, dir_list_len);
			sz = mem_sub(optr, ptr);

			make_string_l(&user_name, optr, sz);

			ustr=user_name.str;

			if (tree_manager_add_child_node(accnt_list, ustr, 0x00000400, &accnt))
			{
				struct string user_pw_file = { (void *)0x00000000L };

				tree_manager_set_child_value_vstr(&accnt, "name", &user_name);

				make_string(&user_pw_file, "acpw");
				cat_cstring_p(&user_pw_file, user_name.str);
				
				if (stat_file(user_pw_file.str) == 0)
					tree_manager_set_child_value_i32(&accnt, "pw", 1);
				else
					tree_manager_set_child_value_i32(&accnt, "pw", 0);

				free_string(&user_pw_file);
				release_zone_ref(&accnt);
			}
			free_string(&user_name);

			cur++;
			optr = ptr + 1;
			dir_list_len -= sz;
		}
	}
	free_string(&user_list);
	return 1;
}


__declspec(dllexport) int  node_get_service_script_assets(const char *service_name,const char *scriptFile,mem_zone_ref_ptr files)
{
	mem_zone_ref service = { (void *)0x00000000L };
	mem_zone_ref scripts = { (void *)0x00000000L }, script = { (void *)0x00000000L };
	unsigned int nserv = 0;


	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c(service_name), 0x08000100, &service))return 0;

	if (tree_manager_find_child_node(&service, calc_crc32_c("nodescripts"), 0x09000001, &scripts))
	{
		if (tree_manager_find_child_node(&scripts, calc_crc32_c(scriptFile), 0x08000400, &script))
		{
			mem_zone_ref	 oList = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
			mem_zone_ref_ptr file = (void *)0x00000000L;

			tree_manager_find_child_node(&script, calc_crc32_c("scripts"), 0xFFFFFFFF, &oList);
			for (tree_manager_get_first_child(&oList, &my_list, &file); ((file != (void *)0x00000000L) && (file->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &file))
			{
				tree_manager_node_add_child(files, file);
			}
			release_zone_ref(&oList);

			tree_manager_find_child_node(&script, calc_crc32_c("stylesheets"), 0xFFFFFFFF, &oList);
			for (tree_manager_get_first_child(&oList, &my_list, &file); ((file != (void *)0x00000000L) && (file->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &file))
			{
				tree_manager_node_add_child(files, file);
			}

			release_zone_ref(&oList);
			release_zone_ref(&script);
		}
		release_zone_ref(&scripts);
	}
	release_zone_ref(&service);
	return 1;
}


int store_last_pos_hash(hash_t hash)
{
	struct string path = { (void *)0x00000000L };
	int ret;
	
	make_string		(&path, "node");
	cat_cstring_p	(&path, "last_pos");
	ret = put_file	(path.str, hash, sizeof(hash_t));
	free_string		(&path);
	return (ret > 0);
}

int store_last_pow_hash(hash_t hash)
{
	struct string path = { (void *)0x00000000L };
	int ret;

	make_string(&path, "node");
	cat_cstring_p(&path, "last_pow");
	ret=put_file(path.str, hash, sizeof(hash_t));
	free_string(&path);
	return ret;
}



__declspec(dllexport) int  node_store_last_pos_hash(mem_zone_ref_ptr blk)
{
	hash_t hash;
	if (!tree_manager_get_child_value_hash(blk,calc_crc32_c("blkHash"),hash))return 0;
	return store_last_pos_hash(hash);
}

__declspec(dllexport) int  node_store_last_pow_hash(mem_zone_ref_ptr blk)
{
	hash_t hash;
	if (!tree_manager_get_child_value_hash(blk, calc_crc32_c("blkHash"), hash))return 0;
	return store_last_pow_hash(hash);
}

__declspec(dllexport) int  node_add_tmp_file(mem_zone_ref_ptr file)
{
	hash_t			dataHash;
	mem_zone_ref	node_files = { (void *)0x00000000L };
	struct string	file_path = { 0 };
	size_t			start = 0, end = 0;
	unsigned int	deltime;

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("tmp files"), 0x09000001, &node_files))return 0;

	
	deltime=get_time_c()+240;
	tree_manager_get_child_value_i32(file, calc_crc32_c("start"), &start);
	tree_manager_get_child_value_i32(file, calc_crc32_c("end"), &end);
	tree_manager_set_child_value_i32(file, "deltime",deltime );

	if (!tree_manager_get_child_value_hash(file, calc_crc32_c("dataHash"), dataHash))
	{
		char chash[65];
		struct string value = { 0 }, tmp_file = { 0 };
		unsigned int n;

		tree_manager_get_child_value_istr	(file, calc_crc32_c("value"), &value,0);

		mbedtls_sha256						(value.str, value.len, dataHash, 0);
		tree_manager_set_child_value_hash	(file, "dataHash"	, dataHash);
		tree_manager_set_child_value_i32	(file, "size"		, value.len);

		n = 0;
		while (n < 32)
		{
			chash[n * 2 + 0] = hex_chars[dataHash[n] >> 0x04];
			chash[n * 2 + 1] = hex_chars[dataHash[n] & 0x0F];
			n++;
		}
		chash[64] = 0;

		make_string(&tmp_file, "tmp");
		create_dir(tmp_file.str);
		cat_cstring_p(&tmp_file, chash);
		put_file(tmp_file.str, value.str, value.len);
		free_string(&tmp_file);
		free_string(&value);
	}

	if (start < end)
		tree_manager_node_add_child(&node_files, file);

	

	release_zone_ref			(&node_files);

	return 1;
}

__declspec(dllexport) int  node_store_tmp_file(struct string *app_name,mem_zone_ref_ptr file)
{
	hash_t			fileHash;
	mem_zone_ref	node_files = { (void *)0x00000000L };
	struct string	file_path = { 0 };
	size_t			start = 0, end = 0;

	if (!tree_manager_get_child_value_hash(file, calc_crc32_c("dataHash"), fileHash))return 0;

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("tmp files"), 0x09000001, &node_files))return 0;
	
	if (tree_find_child_node_by_member_name_hash(&node_files, 0x00000400, "dataHash", fileHash, (void *)0x00000000L))
	{
		char chash[65];
		struct string tmp_file = { 0 },app_file = { 0 };

		int	 n = 0;

		while (n < 32)
		{
			chash[n * 2 + 0] = hex_chars[fileHash[n] >> 4];
			chash[n * 2 + 1] = hex_chars[fileHash[n] & 0x0F];
			n++;
		}
		chash[64] = 0;

		make_string		(&tmp_file, "tmp");
		cat_cstring_p	(&tmp_file, chash);
		
		make_string		(&app_file, "apps");
		cat_cstring_p	(&app_file, app_name->str);
		cat_cstring_p	(&app_file, "datas");
		cat_cstring_p	(&app_file, chash);

		move_file		(tmp_file.str,app_file.str);
		
		free_string		(&app_file);
		free_string		(&tmp_file);

		tree_remove_child_by_member_value_hash(&node_files, 0x00000400, "dataHash", fileHash);
	}

	release_zone_ref(&node_files);

	return 1;

}

__declspec(dllexport) int  node_rm_tmp_file(struct string *app_name, mem_zone_ref_ptr file)
{
	hash_t			fileHash;
	mem_zone_ref	node_files = { (void *)0x00000000L };
	struct string	file_path = { 0 };
	size_t			start = 0, end = 0;

	if (!tree_manager_get_child_value_hash(file, calc_crc32_c("dataHash"), fileHash))return 0;
	
	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("tmp files"), 0x09000001, &node_files))return 0;

	

	if (tree_find_child_node_by_member_name_hash(&node_files, 0x00000400, "dataHash", fileHash, (void *)0x00000000L))
	{
		char			chash[65];
		struct string	tmp_file = { 0 };
		int				n = 0;

		while (n < 32)
		{
			chash[n * 2 + 0] = hex_chars[fileHash[n] >> 4];
			chash[n * 2 + 1] = hex_chars[fileHash[n] & 0x0F];
			n++;
		}
		chash[64] = 0;

		make_string(&tmp_file, "tmp");
		cat_cstring_p(&tmp_file, chash);
		del_file(tmp_file.str);
		free_string(&tmp_file);

		tree_remove_child_by_member_value_hash(&node_files, 0x00000400, "dataHash", fileHash);
	}

	
	release_zone_ref(&node_files);

	return 1;

}

__declspec(dllexport) int  node_get_hash_idx(uint64_t block_idx,hash_t hash)
{
	mem_zone_ref	block_index_node = { (void *)0x00000000L};
	uint64_t		nblks,blkofs;
	int				ret;

	if (!tree_manager_get_child_value_i64(&nself_node, calc_crc32_c("block_height"), &nblks))
		nblks = 0;

	if (block_idx >= nblks)
		return 0;

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("block_index"), 0x0B001000, &block_index_node))
		return 0;
	
	if (block_index_node.zone == (void *)0x00000000L)return 0;

	blkofs = mul64(block_idx, 32);

	ret = tree_manager_get_node_hash(&block_index_node, blkofs, hash);
	release_zone_ref				(&block_index_node);
	
	return ret;
}









































































































































































__declspec(dllexport) int  last_block_locator_index(mem_zone_ref_ptr node, mem_zone_ref_ptr hash_list)
{
	hash_t hash;
	mem_zone_ref hash_node = { (void *)0x00000000L };
	size_t nc;

	if (!tree_manager_create_node("locator", 0x0B400000, hash_list))return 0;
	nc = get_last_block_height();
	node_get_hash_idx(nc - 1, hash);

	tree_manager_add_child_node(hash_list, "hash", 0x0B001000, &hash_node);
	tree_manager_write_node_hash(&hash_node, 0, hash);
	release_zone_ref(&hash_node);

	return 1;
}

__declspec(dllexport) int  get_locator_next_blocks(mem_zone_ref_ptr locator, mem_zone_ref_ptr inv_pack)
{
	hash_t h;
	mem_zone_ref log = { (void *)0x00000000L };
	size_t nhashes;
	uint64_t height = 0,myh,last_block;
	unsigned int n;

	nhashes = tree_manager_get_node_num_children(locator);
	for (n =0; n <nhashes; n++)
	{
		mem_zone_ref nh = { (void *)0x00000000L };

		if (!tree_manager_get_child_at(locator, n, &nh))continue;
		tree_manager_get_node_hash	(&nh, 0,h);
		release_zone_ref			(&nh);
		
		if (find_hash(h))
		{
			char chash[65];
			int	 n = 0;
			
			while (n < 32)
			{
				chash[n * 2 + 0] = hex_chars[h[n] >> 4];
				chash[n * 2 + 1] = hex_chars[h[n] & 0x0F];
				n++;
			}
			chash[64] = 0;
			get_blk_height(chash, &height);
			break;
		}
	}

	myh = get_last_block_height();

	if ((height + 200)>myh)
		last_block = myh;
	else
		last_block = height + 200;

	tree_manager_create_node		("log", 0x0A000010, &log);
	tree_manager_set_child_value_i64(&log, "first", height);
	tree_manager_set_child_value_hash(&log, "firsth", h);
	tree_manager_set_child_value_i64(&log, "last", last_block);
	log_message						("sending block from %first% (%firsth%) to %last%", &log);
	release_zone_ref(&log);
	


	for (n = (height); n < last_block; n++)
	{
		hash_t			h;
		mem_zone_ref	nh = { (void *)0x00000000L };

		node_get_hash_idx			(n, h);
		if (tree_manager_add_child_node(inv_pack, "blkh", 0x0B005000, &nh))
		{
			tree_manager_write_node_hash(&nh, 0, h);
			release_zone_ref(&nh);
		}
	}

	return 1;
}

__declspec(dllexport) int  block_locator_indexes(mem_zone_ref_ptr node, size_t top_height, mem_zone_ref_ptr hash_list)
{
	hash_t hash;
	mem_zone_ref n = { (void *)0x00000000L };
	mem_zone_ref hash_node = { (void *)0x00000000L };
	int64_t index;
	int64_t cnt = 0;
	
	int64_t step = 1;
	int	cn = 0;

	if (!tree_manager_create_node("locator", 0x0B400000, hash_list))return 0;
	
	for (cn = 0, index = (int64_t)(top_height); index > 1; cn++, index -= step)
	{
		char idx[32];

		if (!node_get_hash_idx( index, hash))
			continue;

		strcpy_c(idx, "hash_");
		uitoa_s(cn, &idx[5], 27, 10);


		if (tree_manager_add_child_node(hash_list, idx, 0x0B001000, &hash_node))
		{
			tree_manager_write_node_hash(&hash_node, 0, hash);
			release_zone_ref(&hash_node);
		}
		else
			break;

		
		cnt++;
		if (cnt == 10)
		{
			step = mul64(step, 2);
			cnt = 0;
		}
	}
	
	if (node_get_hash_idx( 0, hash))
	{
		tree_manager_add_child_node(hash_list, "hash", 0x0B001000, &hash_node);
		tree_manager_write_node_hash(&hash_node, 0, hash);
		release_zone_ref(&hash_node);
	}
	log_message("block locator:\n%hash_0%\n%hash_1%\n", hash_list);
	return 1;
}

__declspec(dllexport) int  queue_emitted_message(mem_zone_ref_ptr node, mem_zone_ref_ptr msg)
{
	mem_zone_ref		msg_list = { (void *)0x00000000L };
	int					ret;

	tree_manager_set_child_value_i32(msg, "id", last_msg_id++);
	tree_manager_set_child_value_i32(msg, "recvtime", get_time_c());

	if (!tree_manager_find_child_node(node, calc_crc32_c("emitted_queue"), 0x0B000004, &msg_list))
		tree_manager_add_child_node(node, "emitted_queue", 0x0B000004, &msg_list);

	ret = tree_manager_node_add_child(&msg_list, msg);

	release_zone_ref(&msg_list);

	if (!ret)
		log_output("could not emit message \n");





	return ret;
}


__declspec(dllexport) int  queue_emitted_element(mem_zone_ref_ptr node, mem_zone_ref_ptr element)
{
	mem_zone_ref		list = { (void *)0x00000000L };
	int					ret;

	if (!tree_manager_find_child_node(node, calc_crc32_c("emitted elements"), 0x0B000004, &list))return 0;
	ret = tree_manager_node_add_child(&list, element);
	release_zone_ref(&list);

	return ret;
}

__declspec(dllexport) unsigned int  get_send_queue_length(mem_zone_ref_ptr node)
{
	mem_zone_ref		msg_list = { (void *)0x00000000L };
	unsigned int		num;
	if (!tree_manager_find_child_node(node, calc_crc32_c("send queue"), 0x0B000004, &msg_list))return 0;
	num = tree_manager_get_node_num_children(&msg_list);
	release_zone_ref(&msg_list);
	return num;

}

__declspec(dllexport) int  queue_send_message(mem_zone_ref_ptr node, mem_zone_ref_ptr msg)
{
	mem_zone_ref		msg_list = { (void *)0x00000000L };
	int					ret;

	log_message("queue new message %cmd%", msg);

	tree_manager_set_child_value_i32(msg, "id", last_msg_id++);
	tree_manager_set_child_value_i32(msg, "sent_time", get_time_c());

	if (!tree_manager_find_child_node(node, calc_crc32_c("send queue"), 0x0B000004, &msg_list))
		tree_manager_add_child_node(node, "send queue", 0x0B000004, &msg_list);

	ret = tree_manager_node_add_child(&msg_list, msg);

	release_zone_ref(&msg_list);
	return ret;
}

int find_handler_proc(const char *msg_list_name, mem_zone_ref_ptr msg, mem_zone_ref_ptr script_proc)
{
	mem_zone_ref		handler_list = { (void *)0x00000000L },my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	handler = (void *)0x00000000L;
	int					ret = 0;

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c(msg_list_name), 0x08001000, &handler_list))return 0;

	for (tree_manager_get_first_child(&handler_list, &my_list, &handler); ((handler != (void *)0x00000000) && (handler->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &handler))
	{
		struct key_val	eval;
		struct string	eval_str = { (void *)0x00000000L };
		int				eret;

		make_string				(&eval_str, tree_mamanger_get_node_name(handler));
		eret = parse_query_line	(&eval_str, &eval);
		free_string				(&eval_str);
		if(!eret)continue; 
		
		eret = tree_node_keval	(msg, &eval);
		free_string				(&eval.value);

		if(eret)
		{
			ret = tree_node_find_child_by_type	(handler, 0x08000080, script_proc, 0);
			release_zone_ref					(&my_list);
			dec_zone_ref						(handler);
			break;
		}
	}

	release_zone_ref(&handler_list);

	return ret;
}



__declspec(dllexport) int  node_process_event_handler(const char *msg_list_name, mem_zone_ref_ptr node, mem_zone_ref_ptr msg)
{
	mem_zone_ref		script_proc = { (void *)0x00000000L }, pnode = { (void *)0x00000000L }, ppload = { (void *)0x00000000L }, log = { (void *)0x00000000L };
	int					func_ret=-1;

	if (!find_handler_proc(msg_list_name, msg, &script_proc))return -1;
	
	if (tree_manager_find_child_node(&script_proc, calc_crc32_c("node"), 0xFFFFFFFF, &pnode))
		tree_manager_copy_children_ref(&pnode, node);

	if (tree_manager_find_child_node(msg, calc_crc32_c("payload"), 0x0B000010, &ppload))
	{
		if(tree_manager_swap_child_ref (&script_proc, calc_crc32_c("payload"), 0x0B000010, &ppload))
			release_zone_ref (&ppload);
	}
	
	













	func_ret = execute_script_proc		(&node_script, &script_proc);
	

	tree_manager_create_node			("log", 0x0A000010, &log);
	tree_manager_set_child_value_si32	(&log, "func_ret", func_ret);
	tree_manager_set_child_value_str	(&log, "name", tree_mamanger_get_node_name(&script_proc));
	log_message							("executed script event handler %name% => %func_ret%", &log);
	release_zone_ref					(&log);


	if (func_ret >= 0)
		tree_manager_copy_children_ref(node,&pnode);
	
	release_zone_ref(&pnode);
	release_zone_ref(&script_proc);
	
	return func_ret;
}

__declspec(dllexport) int  node_remove_last_block()
{
	char			chash[65];
	hash_t			hash, null_hash;
	mem_zone_ref	last_hdr = { (void *)0x00000000L };
	mem_zone_ref	block_index_node = { (void *)0x00000000L };
	unsigned int	block_idx;
		
	block_idx = get_last_block_height() - 1;
	if (block_idx == 0)return 0;

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("block_index"), 0x0B001000, &block_index_node))return 0;


	memset_c(null_hash, 0, sizeof(hash_t));
	if (!tree_manager_get_node_hash(&block_index_node, (block_idx)* 32, hash))
	{
		release_zone_ref(&block_index_node);
		return 0;
	}

	if (!remove_block(hash))
	{
		release_zone_ref(&block_index_node);
		return 0;
	}

	tree_manager_write_node_hash(&block_index_node, (block_idx		) *  sizeof(hash_t), null_hash);
	tree_manager_get_node_str	(&block_index_node, (block_idx - 1	) *  sizeof(hash_t), chash, 65, 16);

	if (load_blk_hdr(&last_hdr, chash))
	{
		mem_zone_ref last_blk = { (void *)0x00000000L };

		tree_manager_get_child_value_hash	(&last_hdr, calc_crc32_c("blkHash"), hash);

		tree_manager_find_child_node		(&nself_node, calc_crc32_c("last_block"), 0x0B000800, &last_blk);
		tree_manager_copy_children_ref		(&last_blk, &last_hdr);
		release_zone_ref					(&last_blk);

		if (tree_manager_find_child_node(&last_blk,calc_crc32_c("blk pow"),0xFFFFFFFF,(void *)0x00000000L))
		{
			if (tree_manager_find_child_node(&nself_node, calc_crc32_c("lastPOWBlk"), 0x0B000800, &last_blk))
			{
				tree_manager_copy_children_ref(&last_blk, &last_hdr);
				release_zone_ref(&last_blk);
			}
			store_last_pow_hash(hash);
		}
		else
		{
			if (tree_manager_find_child_node(&nself_node, calc_crc32_c("lastPOSBlk"), 0x0B000800, &last_blk))
			{
				tree_manager_copy_children_ref(&last_blk, &last_hdr);
				release_zone_ref(&last_blk);
			}
			store_last_pos_hash(hash);
		}
		release_zone_ref(&last_hdr);
	}
	else
	{
		log_output("error loading new last blk\n");
	}
	truncate_file					("blk_indexes"	, (block_idx)* 32, (void *)0x00000000L, 0);
	truncate_file					("blk_times"	, (block_idx)* 4, (void *)0x00000000L, 0);
	tree_manager_set_child_value_i64(&nself_node, "block_height", block_idx);


	
	release_zone_ref(&block_index_node);
	
	return (block_idx);
}

__declspec(dllexport) int  node_truncate_chain(uint64_t height)
{
	unsigned int	block_height;

	while ((block_height = get_last_block_height()) > height)
	{
		if (!node_remove_last_block())return 0;
	}
	return block_height;
}


__declspec(dllexport) int  node_truncate_chain_to(mem_zone_ref_ptr nHeight)
{
	uint64_t		height;
	tree_mamanger_get_node_qword	(nHeight, 0, &height);
	return node_truncate_chain		(height);
}

__declspec(dllexport) int  set_next_check(mem_zone_ref_ptr nSecs)
{
	unsigned int		secs;
	unsigned int		next_check;

	tree_mamanger_get_node_dword				(nSecs, 0, &secs);

	next_check	=	get_time_c() + secs;

	return tree_manager_set_child_value_i32		(&nself_node, "next_check", next_check);
}

__declspec(dllexport) int  node_add_block_header(mem_zone_ref_ptr node, mem_zone_ref_ptr hdr)
{
	
	mem_zone_ref		hdr_list = { (void *)0x00000000L };
	int					testing;
	int					ret;

	if (!tree_manager_find_child_node(node, calc_crc32_c("block_headers"), 0x0B000400, &hdr_list))
		tree_manager_add_child_node(node, "block_headers", 0x0B000400, &hdr_list);

	if (tree_manager_node_add_child(&hdr_list, hdr))
	{
		hash_t	bh;
		int		nc;
		if (!tree_manager_get_child_value_hash(hdr, calc_crc32_c("blkHash"), bh))
		{
			compute_block_hash					(hdr, bh);
			tree_manager_set_child_value_bhash	(hdr, "blkHash", bh);
		}
		tree_manager_set_child_value_hash	(node, "last_header_hash", bh);
		if (!tree_manager_get_child_value_i32(node, calc_crc32_c("testing_chain"), &testing))
			testing = 0;

		nc	= tree_manager_get_node_num_children(&hdr_list);
		ret = (testing + nc);
	}

	release_zone_ref(&hdr_list);
	return ret;
}

__declspec(dllexport) int  queue_getblock_hdrs_message(mem_zone_ref_ptr node)
{
	hash_t				null_hash = { 0 };
	mem_zone_ref		blk_pack = { (void *)0x00000000L }, hash_list = { (void *)0x00000000L };
	int					ret = 0;
	size_t				size;
	unsigned int		version;
	
	tree_manager_get_child_value_i32(node, calc_crc32_c("version"), &version);

	size = get_last_block_height();
	block_locator_indexes(&nself_node, size - 1, &hash_list);
	if (create_getheaders_message(&nself_node, version, &hash_list, null_hash, &blk_pack))
	{
		ret = queue_send_message(node, &blk_pack);
		release_zone_ref(&blk_pack);
	}

	release_zone_ref(&hash_list);
	return ret;
}

__declspec(dllexport) int  queue_getblocks_message(mem_zone_ref_ptr node)
{
	mem_zone_ref		getblk_pack = { (void *)0x00000000L }, hash_list = { (void *)0x00000000L };
	size_t				size;
	unsigned int		version;
	int					ret = 0;



	tree_manager_get_child_value_i32(node, calc_crc32_c("version"), &version);
	size = get_last_block_height();
	

	block_locator_indexes(&nself_node, size-1, &hash_list);

	ret = create_getblocks_message(&nself_node, version, &hash_list, &getblk_pack);
	if (ret)
	{
		ret = queue_send_message(node, &getblk_pack);
		release_zone_ref(&getblk_pack);
	}
	release_zone_ref(&hash_list);

	return ret;
}



__declspec(dllexport) int  queue_tx_message(mem_zone_ref_ptr node, mem_zone_ref_ptr tx)
{
	mem_zone_ref		tx_pack = { (void *)0x00000000L };
	int					ret = 0;

	if (create_tx_message(&nself_node, tx, &tx_pack))
	{
		ret = queue_send_message(node, &tx_pack);
		release_zone_ref(&tx_pack);
	}
	return ret;
}


__declspec(dllexport) int  queue_block_message(mem_zone_ref_ptr node, mem_zone_ref_ptr header, mem_zone_ref_ptr tx_list,struct string *signature)
{
	mem_zone_ref		blk_pack = { (void *)0x00000000L };
	int					ret = 0;

	if (create_block_message(&nself_node, header, tx_list, signature, &blk_pack))
	{
		ret = queue_send_message(node, &blk_pack);
		release_zone_ref(&blk_pack);
	}
	return ret;
}


__declspec(dllexport) int  queue_file_message(mem_zone_ref_ptr node, mem_zone_ref_ptr file)
{
	char				fileHash[65];
	struct string		app_name = { 0 }, file_path = { 0 };
	mem_zone_ref		file_pack = { (void *)0x00000000L };
	unsigned char		*fileData;
	int					ret = 0;
	size_t				fileLen;

	tree_manager_get_child_value_istr(file, calc_crc32_c("appName"), &app_name, 0);
	tree_manager_get_child_value_str (file, calc_crc32_c("dataHash"), fileHash,65, 0);

	make_string		(&file_path, "apps");
	cat_cstring_p	(&file_path, app_name.str);
	cat_cstring_p	(&file_path, "datas");
	cat_cstring_p	(&file_path, fileHash);

	if (get_file(file_path.str, &fileData, &fileLen) > 0)
	{
		struct string fileBuff;

		fileBuff.str = fileData;
		fileBuff.len = fileLen;

		tree_manager_set_child_value_vstr(file, "fileData", &fileBuff);
		if (create_file_message(&nself_node, file, &file_pack))
		{
			ret = queue_send_message(node, &file_pack);
			release_zone_ref(&file_pack);
		}

		free_c(fileData);
	}

	free_string(&file_path);
	free_string(&app_name);
	return ret;
}


__declspec(dllexport) int  queue_getdata_message(mem_zone_ref_ptr node, mem_zone_ref_ptr hash_list)
{
	mem_zone_ref		blk_pack = { (void *)0x00000000L }, my_hash_list = { (void *)0x00000000L }, data_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	hash_node = (void *)0x00000000L;
	int					ret = 0;

	




	

	tree_manager_create_node("hashes", 0x0B003000, &data_list);
	for (tree_manager_get_first_child(hash_list, &my_hash_list, &hash_node); ((hash_node != (void *)0x00000000L) && (hash_node->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_hash_list, &hash_node))
	{
		switch (tree_mamanger_get_node_type(hash_node))
		{
			case 0x0B005000:
				if (!node_has_block(hash_node))
				{
					hash_t h;
					tree_manager_node_add_child(&data_list, hash_node);

					tree_manager_get_node_hash(hash_node, 0, h);

					



				}
			break;
			case 0x0B007000:
				if (!node_mempool_has_tx(hash_node))
					tree_manager_node_add_child(&data_list, hash_node);
			break;
			case 0x0A000080:
			{
				hash_t		 fh;
				mem_zone_ref mempool = { (void *)0x00000000L }, tx = { (void *)0x00000000L };
				unsigned char *hash_data;
				hash_data = tree_mamanger_get_node_data_ptr(hash_node, 0);

				node_aquire_mempool_lock(&mempool);
				ret = tree_find_child_node_by_member_name_hash(&mempool, 0x0B008000, "txid", hash_data, &tx);
				if (ret)
				{
					
					struct string appName = { 0 };
					tree_manager_get_child_value_istr	(&tx, calc_crc32_c("appFile"), &appName,0);
					tree_manager_get_child_value_hash	(&tx, calc_crc32_c("fileHash"), fh);
					ret=has_app_file					(&appName, fh);
					free_string							(&appName);
					release_zone_ref					(&tx);
				}
				release_zone_ref(&mempool);
				node_release_mempool_lock();
				
				if (!ret)
				{
					hash_t bh;
					mem_zone_ref  tx = { (void *)0x00000000L };;
					ret = load_tx(&tx, bh, hash_data);
					if (ret){

						struct string appName = { 0 };
						mem_zone_ref file = { (void *)0x00000000L };
						tree_manager_create_node("file", 0x00000400, &file);
						ret = tx_is_app_file(&tx, &appName, &file);
						if (ret)
						{
							tree_manager_get_child_value_hash	(&file, calc_crc32_c("dataHash"), fh);
							ret = has_app_file					(&appName, fh);
						}
						release_zone_ref(&file);
					}
					release_zone_ref(&tx);
				}
				

				if (!ret)
				{
					mem_zone_ref pending = { (void *)0x00000000L }, newf = { (void *)0x00000000L };

					tree_manager_find_child_node(&nself_node, calc_crc32_c("pending files"), 0x0B003000, &pending);

					if (tree_manager_add_child_node(&pending, "file",0x00000400,&newf))
					{
						tree_manager_set_child_value_hash	(&newf, "hash", hash_data);
						tree_manager_set_child_value_i32	(&newf, "time", get_time_c());
						release_zone_ref					(&newf);
					}
					release_zone_ref(&pending);

					tree_manager_node_add_child(&data_list, hash_node);
				}
			}
			break;
		}
	}

	if (tree_manager_get_node_num_children(&data_list) > 0)
	{
		if (create_getdata_message(&nself_node, &data_list, &blk_pack))
		{
			ret = queue_send_message(node, &blk_pack);
			release_zone_ref(&blk_pack);
		}
	}

	release_zone_ref(&data_list);
	return ret;
}

__declspec(dllexport) int  queue_inv_message(mem_zone_ref_ptr node, mem_zone_ref_ptr hash_list)
{
	mem_zone_ref		inv_pack = { (void *)0x00000000L };
	int					ret = 0;

	if (tree_manager_get_node_num_children(hash_list) <= 0)return 0;

	if (create_inv_message(&nself_node, hash_list, &inv_pack))
	{
		ret = queue_send_message(node, &inv_pack);
		release_zone_ref(&inv_pack);
	}
	return ret;
}

__declspec(dllexport) int  queue_getaddr_message(mem_zone_ref_ptr node)
{
	mem_zone_ref		addr_pack = { (void *)0x00000000L };
	int					ret = 0;

	if (!create_getaddr_message(&nself_node, &addr_pack))return 0;
	ret = queue_send_message(node, &addr_pack);
	release_zone_ref(&addr_pack);
	return ret;
}

__declspec(dllexport) int  node_log_addr_infos(mem_zone_ref_ptr node_addr)
{
	log_message("new address %addr%:%port% %time% %services%", node_addr);
	return 1;
}

__declspec(dllexport) int  node_log_version_infos(mem_zone_ref_ptr node)
{
	char user_agent[256];
	mem_zone_ref log = { (void *)0x00000000L };
	mem_zone_ref addrs1 =  (void *)0x00000000L ,addrs2 = (void *)0x00000000L;
	uint64_t     services;
	ipv4_t		 node_ip, my_ip;
	unsigned int proto_ver, last_blk, node_port, my_port;
	const char *services_str;

	if (tree_manager_find_child_node(node, calc_crc32_c("p2p_addr"), 0x0B000040, &addrs1))
	{
		tree_manager_get_child_value_ipv4(&addrs1, calc_crc32_c("addr"), my_ip);
		tree_manager_get_child_value_i32(&addrs1, calc_crc32_c("port"), &my_port);
		tree_manager_get_child_value_i64(&addrs1, calc_crc32_c("services"), &services);

		release_zone_ref(&addrs1);
	}

	if (tree_manager_find_child_node(node, calc_crc32_c("my_addr"), 0x0B000040, &addrs2))
	{
		tree_manager_get_child_value_ipv4(&addrs2, calc_crc32_c("addr"), node_ip);
		tree_manager_get_child_value_i32(&addrs2, calc_crc32_c("port"), &node_port);
		release_zone_ref(&addrs2);
	}
			
	tree_manager_get_child_value_i32(node, calc_crc32_c("block_height"), &last_blk);
	tree_manager_get_child_value_i32(node, calc_crc32_c("version"), &proto_ver);
	tree_manager_get_child_value_str(node, calc_crc32_c("user_agent"), user_agent, 256, 0);

	services_str=services ? "network" : "no services";

	tree_manager_create_node("log", 0x0A000010, &log);
	tree_manager_set_child_value_ipv4(&log, "nip", node_ip);
	tree_manager_set_child_value_i32(&log, "nport", node_port);
	tree_manager_set_child_value_ipv4(&log, "ip", my_ip);
	tree_manager_set_child_value_i32(&log, "port", my_port);
	tree_manager_set_child_value_str(&log, "services", services_str);
	tree_manager_set_child_value_i32(&log, "version", proto_ver);
	tree_manager_set_child_value_str(&log, "user_agent", user_agent);
	tree_manager_set_child_value_i32(&log, "lastblk", last_blk);
	log_message("node %nip%:%nport% %user_agent% version %version% %services% last block: %lastblk%, me %ip%:%port%", &log);
	release_zone_ref(&log);

	return 1;
}

__declspec(dllexport) int  queue_addr_message(mem_zone_ref_ptr node, mem_zone_ref_ptr addrs)
{
	mem_zone_ref		addr_pack = { (void *)0x00000000L };
	int					ret = 0;
	
	if (!create_addr_message(&nself_node, addrs, &addr_pack))return 0;
	ret = queue_send_message(node, &addr_pack);
	release_zone_ref		(&addr_pack);

	return ret;
}

__declspec(dllexport) int  queue_ping_message(mem_zone_ref_ptr node)
{
	mem_zone_ref		pong_pack = { (void *)0x00000000L };
	int					ret = 0;
	uint64_t			nonce;

	if (!tree_manager_get_child_value_i64(node, calc_crc32_c("ping_nonce"), &nonce))nonce = 1;
	if (!create_ping_message(&nself_node, nonce, &pong_pack))return 0;
	ret = queue_send_message(node, &pong_pack);
	release_zone_ref(&pong_pack);

	if (ret)
	{
		ctime_t mytime;
		get_system_time_c(&mytime);
		nonce++;

		tree_manager_set_child_value_i64 (node, "ping_nonce", nonce);
		tree_manager_set_child_value_si64(node, "ping_delay", 0);
		tree_manager_set_child_value_si64(node, "last_ping" , mytime);

		mytime+=30000;

		tree_manager_set_child_value_si64(node, "next_pong", mytime);
	}
	return ret;
}

__declspec(dllexport) int  queue_pong_message(mem_zone_ref_ptr node, mem_zone_ref_ptr nonce_ref)
{
	mem_zone_ref		pong_pack = { (void *)0x00000000L };
	uint64_t			nonce;
	int					ret = 0;

	if (!tree_mamanger_get_node_qword(nonce_ref, 0, &nonce))return 0;

	if (!create_pong_message(&nself_node, nonce, &pong_pack))return 0;
	ret = queue_send_message(node, &pong_pack);
	release_zone_ref(&pong_pack);
	return ret;
}


__declspec(dllexport) int  queue_mempool_message(mem_zone_ref_ptr node)
{
	mem_zone_ref		mempool_pack = { (void *)0x00000000L };
	int					ret = 0;

	if (!create_mempool_message(&nself_node, &mempool_pack))return 0;
	ret = queue_send_message(node, &mempool_pack);
	release_zone_ref(&mempool_pack);
	return ret;
}

__declspec(dllexport) int  queue_verack_message(mem_zone_ref_ptr node)
{
	mem_zone_ref		ver_pack = { (void *)0x00000000L };
	int					ret = 0;

	if (!create_verack_message(&nself_node, &ver_pack))return 0;
	ret = queue_send_message(node, &ver_pack);
	release_zone_ref(&ver_pack);



	return ret;
}

__declspec(dllexport) int  queue_version_message(mem_zone_ref_ptr node)
{
	mem_zone_ref		node_addr = { (void *)0x00000000L },ver_pack = { (void *)0x00000000L };
	int					ret = 0;

	if (!tree_manager_find_child_node(node, calc_crc32_c("p2p_addr"), 0x0B000040, &node_addr))return 0;
	

	if (!create_version_message(&nself_node, &node_addr, &ver_pack))return 0;
	ret = queue_send_message(node, &ver_pack);
	release_zone_ref(&ver_pack);
	release_zone_ref(&node_addr);
	return ret;
}

__declspec(dllexport) int  node_get_root_app(mem_zone_ref_ptr txh)
{
	return get_root_app(txh);
}

__declspec(dllexport) int  node_get_root_app_addr(mem_zone_ref_ptr addr)
{
	return get_root_app_addr(addr);
}

__declspec(dllexport) int  node_get_root_app_fee(mem_zone_ref_ptr fee)
{
	return get_root_app_fee(fee);
}


__declspec(dllexport) int  node_get_apps(mem_zone_ref_ptr apps)
{
	mem_zone_ref tmp = { (void *)0x00000000L };
	if (get_apps(&tmp))
	{
		tree_manager_copy_children_ref(apps, &tmp);
		release_zone_ref(&tmp);
		return 1;
	}

	return 0;
}

__declspec(dllexport) int  node_find_peers(mem_zone_ref_ptr addrs,ipv4_t ip,unsigned short port)
{
	mem_zone_ref		my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	addr =  (void *)0x00000000L ;

	for (tree_manager_get_first_child(addrs, &my_list, &addr); ((addr != (void *)0x00000000L) && (addr->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &addr))
	{
		ipv4_t addr_ip;
		unsigned short addr_port;

		tree_manager_get_child_value_ipv4	(addr, calc_crc32_c("addr"), addr_ip);
		tree_manager_get_child_value_i16	(addr, calc_crc32_c("port"), &addr_port);

		if ((ip == addr_ip) && (addr_port == port))
		{
			dec_zone_ref(addr);
			release_zone_ref(&my_list);
			return 1;
		}
	}

	return 0;
}


__declspec(dllexport) int  node_add_remote_peers(mem_zone_ref_ptr node, mem_zone_ref_ptr addrs)
{
	mem_zone_ref		node_peers = { (void *)0x00000000L }, my_list = { (void *)0x00000000L }, my_peers = { (void *)0x00000000L };
	mem_zone_ref_ptr	addr = (void *)0x00000000L;


	if (!tree_manager_find_child_node(node, calc_crc32_c("peer_addrs"), 0x0B000020, &node_peers))
		tree_manager_add_child_node(node, "peer_addrs", 0x0B000020, &node_peers);

	tree_manager_find_child_node(&nself_node, calc_crc32_c("peer_addrs"), 0x0B000020, &my_peers);
		

	for (tree_manager_get_first_child(addrs, &my_list, &addr); ((addr != (void *)0x00000000L) && (addr->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &addr))
	{
		ipv4_t addr_ip;
		unsigned short addr_port;

		tree_manager_get_child_value_ipv4(addr, calc_crc32_c("addr"), addr_ip);
		tree_manager_get_child_value_i16(addr, calc_crc32_c("port"), &addr_port);

		if (!node_find_peers(&node_peers, addr_ip, addr_port))
			tree_manager_node_add_child(&node_peers, addr);

		if (!node_find_peers(&my_peers, addr_ip, addr_port))
		{
			connect_peer_node(addr);
		}
	}

	release_zone_ref(&my_peers);
	release_zone_ref(&node_peers);


	return 1;
}

__declspec(dllexport) int  node_get_app(mem_zone_ref_ptr appName,mem_zone_ref_ptr app)
{
	char			app_name[32];
	mem_zone_ref	tmp = { (void *)0x00000000L }, tmp2 = { (void *)0x00000000L };
	int				ret;
	
	if (!tree_manager_get_node_str(appName, 0, app_name, 32, 0))return 0;
	if (!get_apps(&tmp))return 0;
	
	ret = tree_manager_find_child_node(&tmp, calc_crc32_c(app_name), 0x0B008000, &tmp2);
	if (ret)
	{
		tree_manager_copy_children_ref(app, &tmp2);
		release_zone_ref(&tmp2);
	}
	release_zone_ref(&tmp);
	return ret;
}

__declspec(dllexport) int  node_get_app_objs(mem_zone_ref_ptr appName, mem_zone_ref_ptr objs)
{
	struct string app_name = { 0 };
	int ret;

	if (!tree_manager_get_node_istr(appName, 0, &app_name, 0))return 0;

	ret=get_app_obj_hashes(app_name.str, objs);

	free_string(&app_name);

	return ret;
}

__declspec(dllexport) int  node_get_types_def(mem_zone_ref_ptr types)
{
	mem_zone_ref type = { (void *)0x00000000L };

	tree_remove_children(types);

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "text");
		tree_manager_set_child_value_i32(&type, "id", 0x0B000100);
		release_zone_ref(&type);
	}

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "uint32");
		tree_manager_set_child_value_i32(&type, "id", 0x00000002);
		release_zone_ref(&type);
	}

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "int32");
		tree_manager_set_child_value_i32(&type, "id", 0x00000008);
		release_zone_ref(&type);
	}

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "uint64");
		tree_manager_set_child_value_i32(&type, "id", 0x00000100);
		release_zone_ref(&type);
	}

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "int64");
		tree_manager_set_child_value_i32(&type, "id", 0x00000800);
		release_zone_ref(&type);
	}

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "float");
		tree_manager_set_child_value_i32(&type, "id", 0x00001000);
		release_zone_ref(&type);
	}

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "double");
		tree_manager_set_child_value_i32(&type, "id", 0x00004000);
		release_zone_ref(&type);
	}

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "vec3");
		tree_manager_set_child_value_i32(&type, "id", 0x0D000002);
		release_zone_ref(&type);
	}
	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "bin");
		tree_manager_set_child_value_i32(&type, "id", 0x0A000040);
		release_zone_ref(&type);
	}
	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "color");
		tree_manager_set_child_value_i32(&type, "id", 0x00000080);
		release_zone_ref(&type);
	}

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "childs");
		tree_manager_set_child_value_i32(&type, "id"  , 0x09000001);
		release_zone_ref(&type);
	}

	if (tree_manager_add_child_node(types, "type", 0x00000400, &type))
	{
		tree_manager_set_child_value_str(&type, "name", "pub childs");
		tree_manager_set_child_value_i32(&type, "id", 0x09000002);
		release_zone_ref(&type);
	}


	return 1;
}

__declspec(dllexport) int  node_get_app_types_def(mem_zone_ref_ptr appName, mem_zone_ref_ptr types)
{
	char				app_name[32];
	mem_zone_ref		tmp = { (void *)0x00000000L }, app_types = { (void *)0x00000000L }, my_list = { (void *)0x00000000L }, app = { (void *)0x00000000L };
	mem_zone_ref_ptr	typetx = (void *)0x00000000L;
	int					ret;

	tree_manager_get_node_str(appName, 0, app_name, 32, 0);
	if (!get_apps(&tmp))return 0;
	ret = tree_manager_find_child_node(&tmp, calc_crc32_c(app_name), 0x0B008000, &app);
	release_zone_ref(&tmp);
	if (!ret)return 0;

	tree_remove_children(types);

	get_app_types(&app, &app_types);

	for (tree_manager_get_first_child(&app_types, &my_list, &typetx); ((typetx != (void *)0x00000000) && (typetx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &typetx))
	{
		char			typeName[33];
		mem_zone_ref	 new_type = { (void *)0x00000000L };
		unsigned int	type_id;
		tree_manager_get_child_value_str(typetx, calc_crc32_c("typeName")	, typeName, 33, 0);
		tree_manager_get_child_value_i32(typetx, calc_crc32_c("typeId")	, &type_id);
		
		if (tree_manager_add_child_node(types, "type", 0x00000400, &new_type))
		{
			mem_zone_ref new_type_keys = { (void *)0x00000000L };
			tree_manager_set_child_value_str(&new_type, "name", typeName);
			tree_manager_set_child_value_i32(&new_type, "id", type_id);

			if (tree_manager_add_child_node(&new_type, "keys", 0x09000001, &new_type_keys))
			{
				mem_zone_ref		my_klist = { (void *)0x00000000L }, type_outs = { (void *)0x00000000L };
				mem_zone_ref_ptr	key = (void *)0x00000000L;
				unsigned int		oidx;

				tree_manager_find_child_node(typetx, calc_crc32_c("txsout"), 0x0B080000, &type_outs);

				for (oidx = 0, tree_manager_get_first_child(&type_outs, &my_klist, &key); ((key != (void *)0x00000000) && (key->zone != (void *)0x00000000)); oidx++,tree_manager_get_next_child(&my_klist, &key))
				{
					struct string	KeyStr = { 0 };
					char			KeyName[32];
					unsigned int	KeyId,flags;
					uint64_t		amount=0;

					if (oidx == 0)continue;
					
					tree_manager_get_child_value_i64(key, calc_crc32_c("value"), &amount);
					if (amount != 0)continue;

					tree_manager_get_child_value_istr(key, calc_crc32_c("script"), &KeyStr, 0);
					
					if (get_type_infos(&KeyStr, KeyName, &KeyId,&flags))
					{
						mem_zone_ref key = { 0 };
						if (tree_manager_add_child_node(&new_type_keys, "type", 0x00000400, &key))
						{
							tree_manager_set_child_value_str(&key, "name", KeyName);
							tree_manager_set_child_value_i32(&key, "id"	 , KeyId);
							release_zone_ref(&key);
						}
					}
					free_string(&KeyStr);
				}
				release_zone_ref(&new_type_keys);
				release_zone_ref(&type_outs);
			}
			release_zone_ref(&new_type);
		}
		
	}

	release_zone_ref(&app);
	release_zone_ref(&app_types);

	return 1;
}

__declspec(dllexport) int  node_fill_block_from_mempool(mem_zone_ref_ptr block)
{
	hash_t				merkleRoot,bh,txh;
	mem_zone_ref		vout = { (void *)0x00000000L }, node_txs = { (void *)0x00000000L }, first_tx = { (void *)0x00000000L },my_list = { (void *)0x00000000L }, tx_list = { (void *)0x00000000L }, stake_tx = { (void *)0x00000000L };
	mem_zone_ref_ptr	tx = (void *)0x00000000L;
	size_t				total_size,block_limit=1024*1024;
	uint64_t			val,total_fees = 0;

	node_aquire_mempool_lock(&node_txs);
	
	
	if (!tree_manager_find_child_node(block, calc_crc32_c("txs"), 0x0B004000, &tx_list))
		tree_manager_add_child_node(block, "txs", 0x0B004000, &tx_list);
		
	
	total_size = 0;

	for (tree_manager_get_first_child(&tx_list, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &tx))
	{
		size_t size;
		if (tree_manager_get_child_value_i32(tx, calc_crc32_c("size"), &size))
			total_size += size;

		if (total_size >= block_limit)
		{
			dec_zone_ref(tx);
			release_zone_ref(&my_list);
			break;
		}
	}

	for (tree_manager_get_first_child(&node_txs, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &tx))
	{
		size_t size;
		uint64_t fee;
		
		if (tree_manager_get_child_value_i32(tx, calc_crc32_c("size"), &size))
			total_size += size;

		if (tree_manager_get_child_value_i64(tx, calc_crc32_c("fee"), &fee))
			total_fees += fee;

		if (total_size >= block_limit)
		{
			dec_zone_ref(tx);
			release_zone_ref(&my_list);
			break;
		}
		tree_manager_node_add_child(&tx_list, tx);
	}

	tree_manager_get_child_at			(&tx_list, 0, &first_tx);

	if (is_tx_null(&first_tx))
	{
		uint64_t new_val;
		tree_manager_get_child_at			(&tx_list, 1, &stake_tx);
		get_tx_output						(&stake_tx, 1, &vout);
		tree_manager_get_child_value_i64	(&vout, calc_crc32_c("value"), &val);

		new_val	=	val+total_fees;

		tree_manager_set_child_value_i64	(&vout, "value", new_val);
		release_zone_ref					(&vout);

		compute_tx_hash						(&stake_tx,txh);
		tree_manager_set_child_value_hash	(&stake_tx, "txid", txh);
		release_zone_ref					(&stake_tx);
	}
	else
	{
		uint64_t new_val;

		get_tx_output						(&first_tx, 0, &vout);
		tree_manager_get_child_value_i64	(&vout, calc_crc32_c("value"), &val);

		new_val	=	val+total_fees;

		tree_manager_set_child_value_i64	(&vout, "value", new_val);
		release_zone_ref					(&vout);
	}

	release_zone_ref	(&first_tx);


	build_merkel_tree					(&tx_list, merkleRoot);
	tree_manager_set_child_value_hash(block, "merkle_root", merkleRoot);

	{
		char logm[65];
		unsigned int n = 0;

		for (n = 0; n < 32; n++)
		{
			logm[n * 2 + 0] = hex_chars[merkleRoot[n] >> 4];
			logm[n * 2 + 1] = hex_chars[merkleRoot[n] & 0x0F];
		}
		logm[64] = 0;
		log_output("merk ");
		log_output(logm);
		log_output("\n");

	}
	compute_block_hash					(block, bh);
	tree_manager_set_child_value_bhash (block, "blkHash", bh);

	release_zone_ref					(&tx_list);
	release_zone_ref					(&node_txs);

	node_release_mempool_lock();

	return 1;
}


__declspec(dllexport) int  node_txsdata_from_mempool(mem_zone_ref_ptr tx_list, mem_zone_ref_ptr Fees)
{
	hash_t				txh;
	mem_zone_ref		vout = { (void *)0x00000000L }, node_txs = { (void *)0x00000000L }, my_list = { (void *)0x00000000L }, stake_tx = { (void *)0x00000000L };
	mem_zone_ref_ptr	tx = (void *)0x00000000L;
	size_t				total_size, block_limit = 1024 * 1024;
	uint64_t			total_fees = 0;
	unsigned int		n;

	
	total_size = 0;
	total_fees = 0;

	for (tree_manager_get_first_child(tx_list, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &tx))
	{
		uint64_t	fee;
		size_t		size;
		if (tree_manager_get_child_value_i32(tx, calc_crc32_c("size"), &size))
			total_size += size;

		if (tree_manager_get_child_value_i64(tx, calc_crc32_c("fee"), &fee))
			total_fees += fee;

		if (total_size >= block_limit)
		{
			dec_zone_ref(tx);
			release_zone_ref(&my_list);
			return 0;
		}
	}

	node_aquire_mempool_lock(&node_txs);

	for (tree_manager_get_first_child(&node_txs, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &tx))
	{
		struct string	txdata = { 0 };
		mem_zone_ref	newtx = { (void *)0x00000000L };
		size_t			size;
		uint64_t		fee;
		unsigned char	*buffer;

		if (tree_manager_get_child_value_i32(tx, calc_crc32_c("size"), &size))
			total_size += size;

		if (total_size >= block_limit)
		{
			dec_zone_ref(tx);
			release_zone_ref(&my_list);
			break;
		}

		if (tree_manager_get_child_value_i64(tx, calc_crc32_c("fee"), &fee))
			total_fees += fee;

		buffer = malloc_c(size);
		write_node(tx, buffer);

		txdata.len	= size * 2;
		txdata.size = txdata.len + 1;
		txdata.str	= malloc_c(txdata.size);
		for (n = 0; n < size; n ++)
		{
			txdata.str[n * 2 + 0] = hex_chars[buffer[n] >> 4];
			txdata.str[n * 2 + 1] = hex_chars[buffer[n] & 0x0F];
		}
		txdata.str[txdata.len] = 0;

		free_c(buffer);

		if (tree_manager_add_child_node(tx_list, "tx", 0x00000400, &newtx))
		{
			tree_manager_get_child_value_hash	(tx, calc_crc32_c("txid"), txh);
			tree_manager_set_child_value_vstr	(&newtx, "data"		, &txdata);
			tree_manager_set_child_value_i64	(&newtx, "fee"		, fee);
			tree_manager_set_child_value_hash	(&newtx, "hash"		, txh);
			tree_manager_set_child_value_bool	(&newtx, "required"	, 1);
			release_zone_ref					(&newtx);
		}
		free_string(&txdata);
	}

	
	release_zone_ref				(&node_txs);
	node_release_mempool_lock		();

	tree_manager_write_node_qword	(Fees, 0, total_fees);

	return 1;
}

__declspec(dllexport) int  node_get_mempool_hashes(mem_zone_ref_ptr hash_list)
{
	mem_zone_ref tx_list = { (void *)0x00000000L }, my_list = { (void *)0x00000000L };
	mem_zone_ref_ptr tx = (void *)0x00000000L;

	tree_remove_children(hash_list);

	node_aquire_mempool_lock( &tx_list);

	

	for (tree_manager_get_first_child(&tx_list, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &tx))
	{
		hash_t txh;

		if (tree_manager_get_child_value_hash(tx, calc_crc32_c("txid"), txh))
		{
			mem_zone_ref nth = { (void *)0x00000000L };

			if (tree_manager_add_child_node(hash_list,"hash", 0x0B007000, &nth))
			{
				tree_manager_write_node_hash(&nth, 0, txh);
				release_zone_ref(&nth);
			}
		}
	}

	release_zone_ref(&tx_list);

	node_release_mempool_lock();
	return 1;
}

__declspec(dllexport) int  node_get_mem_pool(mem_zone_ref_ptr tx_list)
{
	mem_zone_ref node_txs = { (void *)0x00000000L };
	int ret;

	
	node_aquire_mempool_lock(&node_txs);

	ret=tree_manager_copy_children_ref	(tx_list, &node_txs);
	release_zone_ref					(&node_txs);
	node_release_mempool_lock();

	return ret;
}

__declspec(dllexport) int  node_add_tx_to_mempool(mem_zone_ref_ptr tx)
{
	hash_t h;
	mem_zone_ref obj = { (void *)0x00000000L };
	mem_zone_ref node_txs = { (void *)0x00000000L }, log = { (void *)0x00000000L };
	uint64_t total_in, total_out,fees;
	unsigned int coinbase, is_staking;
	int ret;

	

	node_aquire_mempool_lock			(&node_txs);
	compute_tx_hash						(tx, h);
	tree_manager_set_child_value_hash	(tx, "txid", h);

	if (tree_find_child_node_by_member_name_hash(&node_txs,0x0B008000,"txid",h,(void *)0x00000000L))
	{
		log_message					("tx already in mempool %txid%.", tx);
		release_zone_ref			(&node_txs);
		node_release_mempool_lock	();
		
		return 0;
	}
	
	if(is_app_root(tx))
	{
		tree_manager_set_child_value_i32(tx,"is_app_root",1);
		parse_approot_tx				(tx);
	}	
	

	if (tree_manager_find_child_node(tx, calc_crc32_c("objDef"), 0xFFFFFFFF, &obj))
	{
		struct string		appName = { 0 };
		mem_zone_ref		idxs = { (void *)0x00000000L }, m_idlist = { 0 }, m_list = { 0 };
		mem_zone_ref_ptr	idx = (void *)0x00000000L, node_tx=(void *)0x00000000L;
		unsigned int		typeID,unique;

		tree_manager_get_child_value_istr(tx, calc_crc32_c("appObj"), &appName, 0);
		
		typeID = tree_mamanger_get_node_type(&obj);

		tree_manager_create_node("idxs", 0x09000001, &idxs);
		get_app_type_idxs		(appName.str, typeID, &idxs);
		free_string				(&appName);
		unique = 1;

		if (tree_manager_get_node_num_children(&idxs) > 0)
		{
			for (tree_manager_get_first_child(&node_txs, &m_list, &node_tx); ((node_tx != (void *)0x00000000) && (node_tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&m_list, &node_tx))
			{
				mem_zone_ref node_obj = { (void *)0x00000000L };
				if (!tree_manager_find_child_node(tx, calc_crc32_c("objDef"), typeID, &node_obj))continue;

				for (tree_manager_get_first_child(&idxs, &m_idlist, &idx); ((idx != (void *)0x00000000) && (idx->zone != (void *)0x00000000)); tree_manager_get_next_child(&m_idlist, &idx))
				{
					const char *id_name;
					unsigned int type;
					id_name = tree_mamanger_get_node_name(idx);
					type = tree_mamanger_get_node_type(idx);
					if (type == 0x00000002)
					{
						unsigned int val1, val2;
						tree_manager_get_child_value_i32(&node_obj, calc_crc32_c(id_name), &val1);
						tree_manager_get_child_value_i32(&obj, calc_crc32_c(id_name), &val2);
						if (val1 == val2)
						{
							unique = 0;
							dec_zone_ref(idx);
							release_zone_ref(&m_idlist);
							break;
						}

					}
					else if (type == 0x0B000100)
					{
						struct string val1 = { 0 }, val2 = { 0 };
						tree_manager_get_child_value_istr(&node_obj, calc_crc32_c(id_name), &val1, 0);
						tree_manager_get_child_value_istr(&obj, calc_crc32_c(id_name), &val2, 0);

						if ((val1.len == val2.len) && (!strcmp_c(val1.str, val2.str)))
						{
							unique = 0;
							dec_zone_ref(idx);
							release_zone_ref(&m_idlist);
							break;
						}
					}
				}
				release_zone_ref(&node_obj);

				if (!unique)
				{
					dec_zone_ref(node_tx);
					release_zone_ref(&m_list);
					ret = 0;

					log_output("unique key in object\n");
					break;
				}
			}
		}

		release_zone_ref(&idxs);
		release_zone_ref(&obj);
	}

	if (!ret)
	{
		log_message					("rejected tx mempool : %txid% .", tx);
		release_zone_ref			(&node_txs);
		node_release_mempool_lock	();
		return 0;
	}

	if (tree_manager_find_child_node(tx, calc_crc32_c("submitted"), 0xFFFFFFFF, (void *)0x00000000L))
	{
		ret = tree_manager_node_add_unique_child(&node_txs, tx,"txsin[txid,idx]");

		release_zone_ref						(&node_txs);
		node_release_mempool_lock();

		if (ret)
			log_message								("new tx mempool : %txid% , %size% bytes.", tx);
		else
			log_message								("rejected tx mempool : %txid% .", tx);

		return ret;
	}
	
	if(is_app_root(tx))
	{
		if(get_root_app((void *)0x00000000L))
		{
			log_message("rejected tx mempool app root already set : %txid% .", tx);
			release_zone_ref(&node_txs);

			node_release_mempool_lock();
			return 0;
		}
		ret = tree_manager_node_add_child(&node_txs, tx);
	}
	else
	{
		total_out = 0;
		total_in = 0;

		if (!check_tx_inputs(tx, &total_in, &coinbase,1))
		{
			log_message("rejected tx mempool bad inputs : %txid% , %size% bytes.", tx);
			release_zone_ref(&node_txs);
			node_release_mempool_lock();
			return 0;
		}
		if (!check_tx_outputs(tx, &total_out, &is_staking))
		{
			log_message("rejected tx mempool bad outputs : %txid% , %size% bytes.", tx);
			release_zone_ref(&node_txs);
			node_release_mempool_lock();
			return 0;
		}
	
		if(total_out<=total_in)
		{
			uint64_t node_fees;
			fees = total_in-total_out;
		
			if(!tree_manager_get_child_value_i64(&nself_node,calc_crc32_c("paytxfee"),&node_fees))
				node_fees = 0;

			tree_manager_set_child_value_i64(tx, "fee", fees);
		
			if (fees >= node_fees)
				ret = tree_manager_node_add_unique_child	(&node_txs, tx, "txsin[txid,idx]");
			else
				ret = 0;
		}
		else
			ret = 0;
	}
	 
	release_zone_ref					(&node_txs);
	node_release_mempool_lock			();

	if (ret)
		log_message		("new tx mempool : %txid% , %size% bytes.", tx);
	else
		log_message		("mempool tx  rejected %txid%.", tx);
		
	return ret;
}


__declspec(dllexport) int  check_tx_files(mem_zone_ref_ptr node,mem_zone_ref_ptr tx)
{
	mem_zone_ref files = { (void *)0x00000000L };
	if (tree_manager_create_node("files", 0x0B003000, &files))
	{
		get_tx_file(tx, &files);
		if (tree_manager_get_node_num_children(&files)>0)
			queue_getdata_message(node, &files);
	}
	release_zone_ref(&files);

	return 1;
}

__declspec(dllexport) int  node_del_txs_from_mempool(mem_zone_ref_ptr tx_list)
{
	mem_zone_ref		my_list = { (void *)0x00000000L }, node_txs = { (void *)0x00000000L };
	mem_zone_ref_ptr	tx = (void *)0x00000000L;


	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("mempool"), 0x0B004000, &node_txs))return 1;
	

	for (tree_manager_get_first_child(tx_list, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &tx))
	{
		hash_t txh;
		tree_manager_get_child_value_hash		(tx, calc_crc32_c("txid"), txh);
		tree_remove_child_by_member_value_hash	(&node_txs, 0x0B008000, "txid", txh);
	}
	release_zone_ref(&node_txs);


	return 1;
}

__declspec(dllexport) int  node_del_btree_from_mempool()
{
	mem_zone_ref		my_list = { (void *)0x00000000L }, node_txs = { (void *)0x00000000L };
	mem_zone_ref_ptr	tx = (void *)0x00000000L;
	node				*blk_tree;

	get_block_tree(&blk_tree);
	if (blk_tree == (void *)0x00000000L)return 1;

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("mempool"), 0x0B004000, &node_txs))return 1;
	

	for (tree_manager_get_first_child(&node_txs, &my_list, &tx); ((tx != (void *)0x00000000) && (tx->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &tx))
	{
		mem_zone_ref		my_ilist = { (void *)0x00000000L };
		mem_zone_ref_ptr	input = (void *)0x00000000L;

		for (tree_manager_get_first_child(tx, &my_ilist, &input); ((input != (void *)0x00000000) && (input->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_ilist, &input))
		{
			tree_entry			et;
			unsigned int		*et_idx=&et[8];

			tree_manager_get_child_value_hash(input, calc_crc32_c("txid")	, et);
			tree_manager_get_child_value_i32 (input, calc_crc32_c("idx")	, et_idx);

			if (bt_search(blk_tree, et)!=(void *)0x00000000L)
				tree_manager_set_child_value_i32(tx, "stored", 1);
		}
	}

	tree_remove_child_by_member_value_dword(&node_txs, 0x0B008000, "stored", 1);
	release_zone_ref(&node_txs);

	

	return 1;
}

__declspec(dllexport) int  node_mempool_has_tx(mem_zone_ref_ptr tx_hash)
{
	hash_t				txh;
	mem_zone_ref		my_list = { (void *)0x00000000L }, node_txs = { (void *)0x00000000L };
	mem_zone_ref_ptr	tx = (void *)0x00000000L;
	int					ret;

	if (!tree_manager_get_node_hash(tx_hash, 0, txh))return 0;

	node_aquire_mempool_lock(&node_txs);
	

	ret = tree_find_child_node_by_member_name_hash(&node_txs, 0x0B008000, "txid", txh, (void *)0x00000000L);
	release_zone_ref(&node_txs);

	node_release_mempool_lock();

	return ret;
}




__declspec(dllexport) int  send_node_messages(mem_zone_ref_ptr node)
{
	unsigned int		ids[64] = { 0 };
	mem_zone_ref		msg_list = { (void *)0x00000000L };
	mem_zone_ref_ptr	msg = (void *)0x00000000L;
	mem_zone_ref		my_list = { (void *)0x00000000L };
	size_t				n_ids = 0;
	unsigned int		recon = 0, p2p_status = 0, entrant = 0, now;
	struct con		    *node_con;
	
	if (!tree_manager_get_child_value_i32(node, calc_crc32_c("p2p_status"), &p2p_status))
		p2p_status = 0;

	if (p2p_status == 0)return 0;
		
	if(!tree_manager_get_child_value_i32(node, calc_crc32_c("entrant"), &entrant))
		entrant=0;
	

	if (!tree_manager_get_child_value_i32(node, calc_crc32_c("need_recon"), &recon))
		recon = 0;

	
	if (!tree_manager_get_child_value_ptr(node, calc_crc32_c("p2p_con"), &node_con))
		return 0;

	if (recon)
	{
		unsigned int ntries;

		if(tree_manager_find_child_node(node, calc_crc32_c("send queue"), 0x0B000004, &msg_list))
		{
			tree_remove_children		(&msg_list);
			release_zone_ref			(&msg_list);
		}
		tree_remove_child_by_type		(node, 0x0B000008);
		tree_manager_set_child_value_si64(node, "last_ping", 0);
		tree_manager_set_child_value_si64(node, "last_pong", 0);
		tree_manager_set_child_value_si64(node, "next_pong", 0);
		tree_manager_set_child_value_si64(node, "last_msg_time", 0);
		
		if(!entrant)
		{
			if (!tree_manager_get_child_value_i32(node, calc_crc32_c("ntries"), &ntries))
				ntries = 0;

			if (ntries < 3)
			{
				log_output	("reconnecting node \n");
				snooze_c	(2000000);
				if (reconnect(node_con))
				{
					unsigned int	tt;
					log_output						("reconnected to node\n");

					queue_version_message			(node);
					tree_manager_set_child_value_i32(node, "ntries", 0);
					tree_manager_set_child_value_i32(node, "need_recon", 0);

					tt=get_time_c() + 1;

					tree_manager_set_child_value_i32(&nself_node, "next_check", tt);
				}
				else
				{
					log_output						("reconnection failed\n");
					tree_manager_set_child_value_i32(node, "ntries", ++ntries);
					return 0;
				}
			}
			else
			{
				log_output("disconnected from node\n");
				tree_manager_set_child_value_ptr(node, "p2p_con"	, (void *)0x00000000L);
				tree_manager_set_child_value_i32(node, "p2p_status"	, 0);
				con_close						(node_con);
				
				return 0;
			}
		}
		else
		{
	    	tree_manager_set_child_value_i32(node, "need_recon", 0);
	    	tree_manager_set_child_value_ptr(node, "p2p_con"	, (void *)0x00000000L);
			tree_manager_set_child_value_i32(node, "p2p_status"	, 0);
			con_close						(node_con);
	    	return 0;
		}
	}

	now = get_time_c();

	tree_manager_find_child_node(node, calc_crc32_c("send queue"), 0x0B000004, &msg_list);

	for (tree_manager_get_first_child(&msg_list, &my_list, &msg); ((msg != (void *)0x00000000) && (msg->zone != (void *)0x00000000)); tree_manager_get_next_child(&my_list, &msg))
	{
		char cmd[12];
		mem_ptr			buffer;
		unsigned int	sent, msg_id, done, send_time;
		size_t			size;
		int				s;

		if (tree_manager_get_child_value_i32(msg, calc_crc32_c("send_time"), &send_time))
		{
			if ((send_time+60) < now)
			{
				if (!tree_manager_get_child_value_ptr(msg, calc_crc32_c("msg_data"), &buffer))
					buffer = (void *)0x00000000L;

				if (buffer != (void *)0x00000000L)
				{
					tree_manager_set_child_value_ptr(msg, "msg_data", (void *)0x00000000L);
					free_c(buffer);
				}
				tree_manager_set_child_value_i32(msg, "done", 1);
				continue;
			}
		}

		if (!tree_manager_get_child_value_i32(msg, calc_crc32_c("done"), &done))done = 0;
		if (done)continue;
		if (!tree_manager_get_child_value_i32(msg, calc_crc32_c("id"), &msg_id))continue;
		if (!tree_manager_get_child_value_i32(msg, calc_crc32_c("size"), &size))continue;
		if (!tree_manager_get_child_value_str(msg, calc_crc32_c("cmd"), cmd, 12, 16))continue;

		if (!tree_manager_get_child_value_ptr(msg, calc_crc32_c("msg_data"), &buffer))
		{
			buffer = serialize_message(msg);
			tree_manager_set_child_value_ptr(msg, "msg_data", buffer);
		}

		if (!tree_manager_get_child_value_i32(msg, calc_crc32_c("sent"), &sent))
			sent = 0;

		if (buffer != (void *)0x00000000L)
		{
			s = send_data_av(node_con, mem_add(buffer, sent), (size + 4 + 12 + 4 + 4) - sent);
			if (s > 0)
			{
				sent = sent + s;
				tree_manager_set_child_value_i32(msg, "sent", sent);
			}
			else
			{
				if (s < 0)
				{
					log_output("connection lost with node \n");
					
					tree_manager_set_child_value_i32(node, "need_recon", 1);
					tree_manager_set_child_value_ptr(msg , "msg_data", (void *)0x00000000L);
					
					if (buffer != (void *)0x00000000L)
						free_c	(buffer);	
				}
				
				dec_zone_ref		(msg);
				release_zone_ref	(&my_list);
				break;
			}
		}
	
		
		if (sent >= (size + 4 + 12 + 4 + 4))
		{
			if (!tree_manager_get_child_value_ptr(msg, calc_crc32_c("msg_data"), &buffer))
				buffer = (void *)0x00000000L;

			if (buffer != (void *)0x00000000L)
			{
				tree_manager_set_child_value_ptr(msg, "msg_data", (void *)0x00000000L);
				free_c(buffer);
			}
			tree_manager_set_child_value_i32(msg, "done", 1);
		}
	}
	


	tree_remove_child_by_member_value_dword		(&msg_list, 0x0B000008, "done", 1);
	release_zone_ref(&msg_list);

	return 1;
}

__declspec(dllexport) int  read_node_msg(mem_zone_ref_ptr node)
{
	mem_zone_ref			msg = { (void *)0x00000000L };
	struct con				*node_con;
	size_t					ofset;
	unsigned int			magic,status=0;
	int						r;


	if (!tree_manager_get_child_value_i32(node, calc_crc32_c("p2p_status"),  &status))return 0;
	if(status==0)return 0;

	if (!tree_manager_get_child_value_ptr(node, calc_crc32_c("p2p_con"), &node_con))return 0;
	if(node_con==(void *)0x00000000L)return 0;


	if (tree_manager_find_child_node(node, calc_crc32_c("emitting"), 0x0B000008, &msg))
	{
		size_t			size;
		unsigned int	done;
		size_t			recv;
		if (!tree_manager_get_child_value_i32(&msg, calc_crc32_c("done"), &done))
			done = 0;

		if (done == 0)
		{
			char cmd[12];
			size_t			cnt = 0;
			size_t			elSz = 0;
			size_t			elRd = 0;
			unsigned int	elType;

			if (!tree_manager_get_child_value_i32(&msg, calc_crc32_c("size"), &size))
				size = 0;

			if (!tree_manager_get_child_value_i32(&msg, calc_crc32_c("recv"), &recv))
				recv = 0;

			tree_manager_get_child_value_str(&msg, calc_crc32_c("cmd"), cmd, 32, 16);
			tree_manager_get_child_value_i32(&msg, calc_crc32_c("cnt"), &cnt);
			tree_manager_get_child_value_i32(&msg, calc_crc32_c("elSz"), &elSz);
			tree_manager_get_child_value_i32(&msg, calc_crc32_c("elType"), &elType);
			tree_manager_get_child_value_i32(&msg, calc_crc32_c("elRd"), &elRd);

			if (cnt > 0)
			{
				if (recv < size)
				{
					if (get_con_lastline(node_con)->len < elSz)
						r = read_av_data(node_con, elSz - get_con_lastline(node_con)->len);

					if (r <= 0)
					{
						release_zone_ref(&msg);
						return 0;
					}

					recv = recv + r;
					tree_manager_set_child_value_i32(&msg, "recv", recv);

					
					if (get_con_lastline(node_con)->len >= elSz)
					{
						if (elRd < cnt)
						{
							mem_zone_ref element = { (void *)0x00000000L };
							if (tree_manager_create_node("hdr", elType, &element))
							{
								struct string *ll = get_con_lastline(node_con);

								read_node						(&element, ll->str,ll->len);
								queue_emitted_element			(node, &element);
								release_zone_ref				(&element);
							}
							tree_manager_set_child_value_i32(&msg, "elRd", ++elRd);
						}
						con_consume_data(node_con, elSz);
					}
					release_zone_ref(&msg);
					return 1;
				}
				else
				{
					if ((elRd*elSz)<size)
						con_consume_data(node_con, size - elRd*elSz);

					tree_manager_set_child_value_i32(&msg, "done", 1);
					queue_emitted_message			(node, &msg);
					tree_remove_child_by_type		(node, 0x0B000008);
					release_zone_ref				(&msg);
				}
			}
			else if (recv < size)
			{
				mem_zone_ref			log = { (void *)0x00000000L };
				r = read_av_data(node_con, size - recv);

				if (r > 0)
				{
					unsigned int new_r=recv+r;

					tree_manager_set_child_value_i32(&msg, "recv", new_r);
					release_zone_ref(&msg);
					return 1;
				}
				else
				{
					release_zone_ref(&msg);
					return 0;
				}
			}
			else
			{
				struct					string msg_str = { 0 };
				unsigned int			checksum1[8];
				unsigned int			checksum[8];
				mem_zone_ref			log = { (void *)0x00000000L },msg_list = { (void *)0x00000000L };
				unsigned int			sum;

				tree_manager_get_child_value_i32(&msg, calc_crc32_c("sum"), &sum);

				mbedtls_sha256(get_con_lastline(node_con)->str, size, (unsigned char*)checksum1, 0);
				mbedtls_sha256((unsigned char*)checksum1, 32, (unsigned char*)checksum, 0);

				if (checksum[0] == sum)
				{
					mem_zone_ref pl = { (void *)0x00000000L };
					struct string *ll = get_con_lastline(node_con);

					if (unserialize_message(&msg, ll->str, ll->len, (void *)0x00000000L))
					{
						tree_manager_set_child_value_i32(&msg, "done", 1);
						queue_emitted_message			(node, &msg);
						release_zone_ref				(&msg);
					}
					else
					{
						log_output("unserialize msg error \n");
					}
					con_consume_data(node_con, size);
				}
				else
				{
					mem_zone_ref log = { (void *)0x00000000L };
					char					cmd_node[12];

					tree_manager_get_child_value_str(&msg, calc_crc32_c("cmd"), cmd_node, 12, 16);

					tree_manager_create_node("log", 0x0A000010, &log);
					tree_manager_set_child_value_str(&log, "cmd", cmd_node);
					tree_manager_set_child_value_str(&log, "lastline", get_con_lastline(node_con)->str);
					tree_manager_set_child_value_i32(&log, "len", get_con_lastline(node_con)->len);
					
					tree_manager_set_child_value_i32(&log, "sum", sum);
					tree_manager_set_child_value_i32(&log, "ssum", checksum[0]);
					tree_manager_set_child_value_i32(&log, "size", size);
					tree_manager_set_child_value_str(&log, "hostname", get_con_hostd(node_con)->host.str);
					tree_manager_set_child_value_i32(&log, "port", get_con_hostd(node_con)->port);
					log_message("message checksum %sum% != %ssum% , %len% '%lastline%' error %cmd%, playload : %size% bytes from '%hostname%':%port%", &log);
					release_zone_ref(&log);
				}
				tree_remove_child_by_type(node, 0x0B000008);
			}
		}
		release_zone_ref(&msg);
	}


	if (get_con_lastline(node_con)->len < 8)
		if (read_av_data(node_con, 8 - get_con_lastline(node_con)->len) < 0)
			return 0;

	if (get_con_lastline(node_con)->len < 8)
		return 0;

	get_magic(&magic);

	if ((ofset = memchr_32_c(get_con_lastline(node_con)->str, magic, 8)) != 0xffffffffUL)
	{
		size_t				cntSz = 0, maxMsgSize;
		size_t				pre_read=0;
		mem_zone_ref log = { (void *)0x00000000L };

		if (ofset>0)
			con_consume_data(node_con, ofset);

		if (get_con_lastline(node_con)->len < 24)
			read_av_data(node_con, 24 - get_con_lastline(node_con)->len);

		if (get_con_lastline(node_con)->len < 24)return 0;

		if (tree_manager_get_child_value_i32(&nself_node, calc_crc32_c("maxMsgSize"), &maxMsgSize))
		{
			if (*((unsigned int *)(&get_con_lastline(node_con)->str[16])) > (maxMsgSize*1024))
				return 0;
		}

		if (*((unsigned int *)(&get_con_lastline(node_con)->str[16])) > 0)
		{
			if (!strncmp_c(&get_con_lastline(node_con)->str[4], "block", 5))
			{
				pre_read = 80 + 9;

				if (get_con_lastline(node_con)->len < 24 + pre_read)
					if ((r = read_av_data(node_con, 24 + pre_read - get_con_lastline(node_con)->len)) <= 0)
						return 0;

				if (get_con_lastline(node_con)->len < 24 + pre_read)
					return 0;
			}
			else if (!strncmp_c(&get_con_lastline(node_con)->str[4], "inv", 3))
			{
				pre_read = 9+1;
				if (get_con_lastline(node_con)->len < 24 + pre_read)
					r = read_av_data(node_con, 24 + pre_read - get_con_lastline(node_con)->len);

				if (get_con_lastline(node_con)->len < 24 + pre_read)
					return 0;
			}
			else if (!strncmp_c(&get_con_lastline(node_con)->str[4], "getdata", 7))
			{
				pre_read = 9+1;
				if (get_con_lastline(node_con)->len < 24 + pre_read)
					r = read_av_data(node_con, 24 + pre_read - get_con_lastline(node_con)->len);

				if (get_con_lastline(node_con)->len < 24 + pre_read)
					return 0;
			}
			else if (!strncmp_c(&get_con_lastline(node_con)->str[4], "getblocks", 9))
			{
				pre_read = 9 + 4;
				if (get_con_lastline(node_con)->len < 24 + pre_read)
					r = read_av_data(node_con, 24 + pre_read - get_con_lastline(node_con)->len);

				if (get_con_lastline(node_con)->len < 24 + pre_read)
					return 0;
			}
			else if ((!strncmp_c(&get_con_lastline(node_con)->str[4], "addr", 4)) || (!strncmp_c(&get_con_lastline(node_con)->str[4], "headers", 7)))
			{
				pre_read = 9;
				if (get_con_lastline(node_con)->len < 24 + pre_read)
					r = read_av_data(node_con, 24 + pre_read - get_con_lastline(node_con)->len);

				if (get_con_lastline(node_con)->len < 24 + pre_read)
					return 0;

				switch (*((unsigned char *)(get_con_lastline(node_con)->str + 24)))
				{
					default:cntSz = 1; break;
					case 0xFD:cntSz = 3; break;
					case 0xFE:cntSz = 5; break;
					case 0xFF:cntSz = 9; break;
				}

				if (!tree_manager_find_child_node(node, calc_crc32_c("emitted elements"), 0x0B000004, (void *)0x00000000L))
					tree_manager_add_child_node(node, "emitted elements", 0x0B000004, (void *)0x00000000L);
			}
			if (tree_manager_create_node("emitting", 0x0B000008, &msg))
			{
				new_message							(get_con_lastline(node_con), &msg);
				tree_manager_node_add_child			(node, &msg);
				tree_manager_set_child_value_i32	(&msg, "recv", pre_read);
				tree_manager_set_child_value_i32	(&msg, "done", 0);
				release_zone_ref					(&msg);
			}
			else
			{
				log_output("error creating new message\n");
			}
		}
		else
		{
			if (tree_manager_create_node("message", 0x0B000008, &msg))
			{
				tree_manager_set_child_value_str(&msg, "cmd", &get_con_lastline(node_con)->str[4]);
				tree_manager_set_child_value_i32(&msg, "size", 0);
				tree_manager_set_child_value_i32(&msg, "sum", *((unsigned int *)(&get_con_lastline(node_con)->str[20])));
				tree_manager_set_child_value_i32(&msg, "recv", 0);
				tree_manager_set_child_value_i32(&msg, "done", 1);
				queue_emitted_message(node, &msg);
				release_zone_ref(&msg);
			}
			else
				log_output("could not create new input message\n");
		}

		if (tree_manager_create_node("log", 0x0A000010, &log))
		{
			tree_manager_set_child_value_str(&log, "cmd", &get_con_lastline(node_con)->str[4]);
			tree_manager_set_child_value_i32(&log, "size", *((unsigned int *)(&get_con_lastline(node_con)->str[16])));
			tree_manager_set_child_value_i32(&log, "sum", *((unsigned int *)(&get_con_lastline(node_con)->str[20])));
			tree_manager_set_child_value_str(&log, "hostname", get_con_hostd(node_con)->host.str);
			tree_manager_set_child_value_i32(&log, "port", get_con_hostd(node_con)->port);
			log_message("msg %cmd%, %sum% %size% bytes from '%hostname%':%port% ", &log);
			release_zone_ref(&log);
		}

		con_consume_data(node_con, 24 + cntSz);

	}
	else
		con_consume_data(node_con, 4);

	return 1;
}

__declspec(dllexport) int  node_send_block(mem_zone_ref_ptr node, mem_zone_ref_ptr blk_hash)
{
	char			chash[65];
	mem_zone_ref	block = { (void *)0x00000000L }, txs = { (void *)0x00000000L };
	unsigned char	*hash_data;
	int				n = 0;
	
	hash_data = tree_mamanger_get_node_data_ptr(blk_hash, 0);
	
	while (n < 32)
	{
		chash[n * 2 + 0] = hex_chars[hash_data[n] >> 4];
		chash[n * 2 + 1] = hex_chars[hash_data[n] & 0x0F];
		n++;
	}
	chash[64] = 0;
	
	if (load_blk_hdr(&block, chash))
	{
		if (tree_manager_create_node("txs", 0x0B004000, &txs))
		{
			struct string sign = { 0 };
			
			tree_manager_get_child_value_istr		(&block,calc_crc32_c("signature"),&sign,0);
			if (load_blk_txs(chash, &txs))
			{
				unsigned char vntx[2] = { 0 };
				tree_manager_set_child_value_vint	(&block, "ntx", vntx);
				queue_block_message					(node, &block, &txs, &sign);
			}
			release_zone_ref(&txs);
			free_string		(&sign);
		}
		release_zone_ref(&block);
	}
	
	return 1;
}

__declspec(dllexport) int  node_send_addr(mem_zone_ref_ptr node, mem_zone_ref_ptr p2p_addr)
{
	mem_zone_ref	addrs = { (void *)0x00000000L };

	tree_manager_create_node		("addrs", 0x0B000020, &addrs);
	tree_manager_node_add_child		(&addrs, p2p_addr);
	queue_addr_message				(node,&addrs);
	release_zone_ref				(&addrs);

	return 1;
}

__declspec(dllexport) int  node_broadcast_addr(mem_zone_ref_ptr p2p_addr)
{
	mem_zone_ref	 my_list = { (void *)0x00000000L }, peer_nodes = { (void *)0x00000000L };
	mem_zone_ref_ptr node = (void *)0x00000000L;

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("peer_nodes"), 0x0B000001, &peer_nodes))
	{
		log_output("no peer nodes \n");
		return 0;
	}

	for (tree_manager_get_first_child(&peer_nodes, &my_list, &node); ((node != (void *)0x00000000L) && (node->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &node))
	{
		node_send_addr(node, p2p_addr);
	}

	release_zone_ref(&peer_nodes);

	return 1;
}

__declspec(dllexport) int  node_send_file(mem_zone_ref_ptr node, mem_zone_ref_ptr file_hash)
{
	hash_t			bh;
	mem_zone_ref	file = { (void *)0x00000000L }, file_tx = { (void *)0x00000000L },mempool = { (void *)0x00000000L };
	struct string	app_name={0};
	unsigned char	*hash_data;
	int				n = 0;
	int				ret;

	hash_data = tree_mamanger_get_node_data_ptr(file_hash, 0);
	
	tree_manager_create_node("file", 0x00000400, &file);

	
	node_aquire_mempool_lock(&mempool);
	ret = tree_find_child_node_by_member_name_hash(&mempool, 0x0B008000, "txid", hash_data, &file_tx);
	release_zone_ref(&mempool);
	node_release_mempool_lock();
	

	if (!ret)
	{
		if (!load_tx(&file_tx, bh, hash_data))
			return 0;
	}

	
	if (get_app_file(&file_tx, &app_name, &file))
	{
		tree_manager_set_child_value_vstr	(&file, "appName", &app_name);
		queue_file_message					(node, &file);
		free_string							(&app_name);
	}
	release_zone_ref(&file);
	release_zone_ref(&file_tx);

	return 1;

}

void dump_self()
{
	char buff[32];
	uitoa_s((unsigned int )nself_node.zone, buff, 32, 16);
	log_output("init self [");
	log_output(buff);
	log_output("] [");
	uitoa_s((unsigned int)&nself_node.zone, buff, 32, 16);
	log_output(buff);
	log_output("] [");
	uitoa_s((unsigned int)&nself_node, buff, 32, 16);
	log_output(buff);
	log_output("\n");

}

__declspec(dllexport) int  update_peernodes()
{
	mem_zone_ref_ptr	node = (void *)0x00000000L;
	mem_zone_ref		my_list = { (void *)0x00000000L }, peer_nodes = { (void *)0x00000000L }, node_files = { (void *)0x00000000L }, pending = { (void *)0x00000000L };
	ctime_t				now;
	

	




	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("peer_nodes"), 0x0B000001, &peer_nodes))
	{
		log_output("no peer nodes \n");
		return 0;
	}

	now = get_time_c();

	for (tree_manager_get_first_child(&peer_nodes, &my_list, &node); ((node != (void *)0x00000000L) && (node->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &node))
	{
		mem_zone_ref node_qlist = { (void *)0x00000000L };
		
		if(tree_manager_find_child_node	(node, calc_crc32_c("queried_hashes"), 0x0B003000, &node_qlist))
		{
			mem_zone_ref		my_hash_list = { (void *)0x00000000L };
			mem_zone_ref_ptr	hash_node	=	(void *)0x00000000L;
		
			for (tree_manager_get_first_child(&node_qlist, &my_hash_list, &hash_node); ((hash_node != (void *)0x00000000L) && (hash_node->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_hash_list, &hash_node))
			{
				unsigned int	done;

				if (get_send_queue_length(node) >= 3) {
					dec_zone_ref	(hash_node);
					release_zone_ref(&my_hash_list);
					break;
				}
				
				if (!tree_manager_get_child_value_i32(hash_node, calc_crc32_c("done"), &done))done = 0;
				if (done != 0)continue;
								
				if (tree_mamanger_get_node_type(hash_node) == 0x0B005000)
				{
					node_send_block(node,hash_node);
				}
				if (tree_mamanger_get_node_type(hash_node) == 0x0A000080)
				{
					mem_zone_ref pending = { (void *)0x00000000L };
					unsigned char	*hash_data;
					int				ret;

					hash_data = tree_mamanger_get_node_data_ptr(hash_node, 0);

					tree_manager_find_child_node					(&nself_node, calc_crc32_c("pending files"), 0x0B003000, &pending);
					ret = tree_find_child_node_by_member_name_hash	(&pending, 0x00000400, "hash", hash_data,(void *)0x00000000L);
					release_zone_ref								(&pending);

					if (ret)continue;
					
					node_send_file(node, hash_node);
				}
				else  if (tree_mamanger_get_node_type(hash_node) == 0x0B007000)
				{
					hash_t			blkhash, txh;
					mem_zone_ref	tx = { (void *)0x00000000L };
					mem_zone_ref	block = { (void *)0x00000000L }, txs = { (void *)0x00000000L };
					unsigned char	*hash_data;
					int				n = 32, ret = 0;

					hash_data = tree_mamanger_get_node_data_ptr(hash_node, 0);
					
					while (n--)txh[n] = hash_data[31 - n];

					ret = load_tx(&tx, blkhash, txh);
					if (!ret)
					{
					    mem_zone_ref etx = { (void *)0x00000000L };
						
						node_aquire_mempool_lock(&etx);
						ret = tree_find_child_node_by_member_name_hash(&etx, 0x0B008000, "txid", hash_data, &tx);
						release_zone_ref(&etx);
						node_release_mempool_lock();

					}
					if (ret)
					{
						queue_tx_message(node, &tx);
						release_zone_ref(&tx);
					}
				}
				tree_manager_set_child_value_i32(hash_node, "done", 1);
			}
			tree_remove_child_by_member_value_dword(&node_qlist, 0, "done", 1);
			release_zone_ref(&node_qlist);
		}
		send_node_messages(node);
		read_node_msg(node);
	}
	
	tree_remove_child_by_member_value_dword(&peer_nodes, 0x0B000002, "p2p_status", 0);

	release_zone_ref(&peer_nodes);


	if (tree_manager_find_child_node(&nself_node, calc_crc32_c("tmp files"), 0x09000001, &node_files))
	{
		mem_zone_ref_ptr my_list_ptr;
		mem_zone_ref_ptr file = (void *)0x00000000L;

		if ((get_zone_area_type(&node_files) & 0x10) == 0)
			my_list_ptr = &my_list;

		for (tree_manager_get_first_child_shared(&node_files, &my_list_ptr, &file); ((file != (void *)0x00000000L) && (file->zone != (void *)0x00000000L)); tree_manager_get_next_child_shared(&my_list_ptr, &file))
		{
			unsigned int time;
			tree_manager_get_child_value_i32(file, calc_crc32_c("deltime"), &time);

			if (time<now)
			{
				char			chash[65];
				struct string	tmp_file = { 0 };

				tree_manager_get_child_value_str(file, calc_crc32_c("dataHash"), chash,65,16);

				make_string		(&tmp_file, "tmp");
				cat_cstring_p	(&tmp_file, chash);
				del_file		(tmp_file.str);
				free_string		(&tmp_file);
			}
		}
		tree_remove_child_by_member_value_lt_dword		(&node_files, 0x00000400, "deltime", now);
		release_zone_ref								(&node_files);
	}


	tree_manager_find_child_node				(&nself_node, calc_crc32_c("pending files"), 0x0B003000, &pending);
	tree_remove_child_by_member_value_lt_dword	(&pending, 0x00000400, "time", now-120);
	release_zone_ref							(&pending);

	
	
	return 1;
}
__declspec(dllexport) int  node_get_last_block_time(ctime_t *otime)
{
	mem_zone_ref last_blk = { (void *)0x00000000L };
	unsigned int time;
	int			 ret;
	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("last block"), 0x0B000800, &last_blk))
		return 0;

	ret = tree_manager_get_child_value_i32(&last_blk, calc_crc32_c("time"), &time);
	if (ret)
		*otime = time;
	else
		*otime = 0;

	release_zone_ref(&last_blk);
	return ret;
}



__declspec(dllexport) int  node_has_block(mem_zone_ref_ptr hash)
{
	hash_t		 bh;
	mem_zone_ref block_index_node = { (void *)0x00000000L };
	mem_ptr		 hashes = (void *)0x00000000L;
	size_t		 n_hashes = 0;
	int ret;


	if (!tree_manager_get_node_hash(hash, 0, bh))return 0;
	tree_manager_get_child_value_i32	(&nself_node, calc_crc32_c("block_height"), &n_hashes);
	tree_manager_find_child_node		(&nself_node, calc_crc32_c("block_index"), 0x0B001000, &block_index_node);

	hashes	= tree_mamanger_get_node_data_ptr(&block_index_node, 0);
	ret		= find_mem_hash(bh, hashes, n_hashes);
	release_zone_ref(&block_index_node);
	return ret;
}

__declspec(dllexport) int  node_check_chain(mem_zone_ref_ptr node, mem_zone_ref_ptr hdr)
{
	hash_t			prevHash, bh;
	char			chash[65];
	mem_zone_ref	hash_list = { (void *)0x00000000L }, log = { (void *)0x00000000L };
	int				n, ret = 0;
	uint64_t		height = 0;

	if (!tree_manager_get_child_value_hash(hdr, calc_crc32_c("prev"), prevHash))
	{
		tree_manager_set_child_value_i32(hdr, "keep_block", 0);
		return 0;
	}


	
	if (!find_hash(prevHash))
	{
		ctime_t		 last_time;
		unsigned int time, my_time;

		
		if (node_get_last_block_time(&last_time))
			my_time = last_time;
		else
			my_time = get_time_c();

		if (tree_manager_get_child_value_i32(hdr, calc_crc32_c("time"), &time))
		{
			if (time < my_time)
				tree_manager_set_child_value_i32(hdr, "keep_block", 0);
			else if (((time - my_time) < 600))
				tree_manager_set_child_value_i32(hdr, "keep_block", 1);
			else
				tree_manager_set_child_value_i32(hdr, "keep_block", 0);
		}
		else
			tree_manager_set_child_value_i32(hdr, "keep_block", 0);

		
		return 0;
	}

	tree_manager_get_child_value_hash(hdr, calc_crc32_c("blkHash"), bh);
	
	if (find_hash(bh))
	{
		mem_zone_ref block_index_node = { (void *)0x00000000L };
		mem_ptr		 hashes=(void *)0x00000000L;
		size_t		 n_hashes=0;

		tree_manager_get_child_value_i32(&nself_node, calc_crc32_c("block_height"), &n_hashes);
		tree_manager_find_child_node	(&nself_node, calc_crc32_c("block_index"), 0x0B001000, &block_index_node);

		hashes	=	tree_mamanger_get_node_data_ptr(&block_index_node, 0);
		release_zone_ref(&block_index_node);

		if (!find_mem_hash(bh, hashes, n_hashes))
		{
			
			tree_manager_set_child_value_i32(hdr, "keep_block", 1);
			return 1;
		}
		else
		{
			
			tree_manager_set_child_value_i32(hdr, "keep_block", 0);
			return 0;
		}

		
	}

	n = 0;
	while (n<32)
	{
		chash[n * 2 + 0] = hex_chars[prevHash[n] >> 4];
		chash[n * 2 + 1] = hex_chars[prevHash[n] & 0x0F];
		n++;
	}
	chash[64] = 0;
	
	if (!get_blk_height(chash, &height))
	{
		
		tree_manager_set_child_value_i32(hdr, "keep_block", 0);
		return 0;
	}


	tree_manager_set_child_value_i32(hdr, "keep_block", 1);

	
	if (!node_add_block_header(node, hdr))
		return 0; 

	tree_manager_set_child_value_i32(node, "testing_chain", height);

	tree_manager_create_node("log", 0x0A000010, &log);
	tree_manager_set_child_value_hash(&log, "bh", bh);
	tree_manager_set_child_value_hash(&log, "ph", prevHash);
	tree_manager_set_child_value_i32(&log, "height", height);
	log_message("set chain on testing at height : %height% [%bh%] (prev : '%ph%')", &log);
	release_zone_ref(&log);



return 0;

}


__declspec(dllexport) int  node_get_pow_spacing(mem_zone_ref_ptr lastPOW, mem_zone_ref_ptr Spacing)
{
	char				cpphash[65];
	hash_t				null_hash;
	hash_t				pppp;
	mem_zone_ref		pprev = { (void *)0x00000000L };
	int64_t				spacing;
	unsigned int		prevTime, pprevTime;
	int					ret;
	
	memset_c(null_hash, 0, sizeof(hash_t));
	tree_manager_get_child_value_i32(lastPOW, calc_crc32_c("time"), &prevTime);
	tree_manager_get_child_value_str(lastPOW, calc_crc32_c("prev"), cpphash, 65, 16);

	if (!load_blk_hdr(&pprev, cpphash))return 0;

	tree_manager_get_child_value_hash(&pprev, calc_crc32_c("prev"), pppp);
	if (!memcmp_c(pppp, null_hash, sizeof(hash_t)))
	{
		release_zone_ref(&pprev);
		return 0;
	}
	ret = blk_find_last_pow_block(&pprev, &pprevTime);
	release_zone_ref(&pprev);
	if (!ret)return 0;
	spacing = prevTime - pprevTime;

	tree_manager_write_node_dword(Spacing, 0, spacing);
	return 1;
}

__declspec(dllexport) int  compute_last_pow_diff(mem_zone_ref_ptr blk, mem_zone_ref_ptr nBits)
{
	mem_zone_ref POWSpace = { (void *)0x00000000L };
	unsigned int bits;
	int ret;

	tree_manager_get_child_value_i32(blk, calc_crc32_c("bits"), &bits);
	tree_manager_write_node_dword(nBits, 0, bits);
	tree_manager_create_node("spacing", 0x00000002, &POWSpace);
	ret = node_get_pow_spacing(blk, &POWSpace);
	if (ret) ret = block_compute_pow_target(&POWSpace, nBits);

	release_zone_ref(&POWSpace);

	return ret;
}

int load_last_pow_blk(mem_zone_ref_ptr header)
{
	unsigned char   *data;
	size_t			len;
	struct string	path = { (void *)0x00000000L };
	int				ret=0;

	make_string		(&path, "node");
	cat_cstring_p	(&path, "last_pow");
	if (get_file(path.str, &data, &len) > 0)
	{
		if (len >= sizeof(hash_t))
		{
			char chash[65];
			int	 n;
			n = 0;
			while (n<32)
			{
				chash[n * 2 + 0] = hex_chars[data[n] >> 4];
				chash[n * 2 + 1] = hex_chars[data[n] & 0x0F];
				n++;
			}
			chash[64] = 0;
			ret = load_blk_hdr(header, chash);
		}
		free_c(data);
	}
	free_string		(&path);

	return (ret>0);
}


__declspec(dllexport) int  node_load_last_blks()
{
	hash_t				last_hash;
	char				dd[16];
	mem_zone_ref		last_pow_blk = { (void *)0x00000000L }, last_blk = { (void *)0x00000000L };
	unsigned int		nblks;
	int					ret;

	nblks = get_last_block_height();
	itoa_s(nblks,dd,16,10);

	log_output("load last blk ");
	log_output(dd);
	log_output("\n");

	if ((nblks > 1) && (node_get_hash_idx(nblks - 1, last_hash)))
	{
		char			chash[65];
		int				n;
		unsigned int	nBits,time;


		if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("last_block"), 0x0B000800, &last_blk))
			ret = tree_manager_add_child_node(&nself_node, "last_block", 0x0B000800, &last_blk);

		if (!ret)return 0;

		n = 0;
		while (n<32)
		{
			chash[n * 2 + 0] = hex_chars[last_hash[n] >> 4];
			chash[n * 2 + 1] = hex_chars[last_hash[n] & 0x0F];
			n++;
		}
		chash[64] = 0;


		if (!load_blk_hdr(&last_blk, chash))
		{
			release_zone_ref(&last_blk);
			return 0;
		}

		log_message("loaded last block %blkHash%", &last_blk);

		tree_manager_get_child_value_i32	(&last_blk, calc_crc32_c("time"), &time);
		tree_manager_set_child_value_i32	(&nself_node, "last_block_time", time);

		tree_manager_node_add_child			(&nself_node, &last_blk);

		if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("lastPOWBlk"), 0x0B000800, &last_pow_blk))
			ret=tree_manager_add_child_node(&nself_node,"lastPOWBlk", 0x0B000800, &last_pow_blk);
		
		if(ret)
		{
			mem_zone_ref bits = { (void *)0x00000000L }, POWSpace = { (void *)0x00000000L };

			if (!load_last_pow_blk(&last_pow_blk))
			{
				unsigned int time, lpblk=0;
				
				if (!tree_manager_get_child_value_i32(&nself_node, calc_crc32_c("lastPOWBlk"), &lpblk))
					lpblk = 0;

				if ((lpblk>0)&&(nblks > lpblk))
				{
					char chash[65];
					hash_t h;
					int	 n;
					node_get_hash_idx(lpblk + 1, h);
					n = 0;
					while (n<32)
					{
						chash[n * 2 + 0] = hex_chars[h[n] >> 4];
						chash[n * 2 + 1] = hex_chars[h[n] & 0x0F];
						n++;
					}
					chash[64] = 0;
					load_blk_hdr(&last_pow_blk, chash);
				}
				else
					copy_zone_ref(&last_pow_blk, &last_blk);

				if (blk_find_last_pow_block(&last_pow_blk, &time))
				{
					hash_t h;
					tree_manager_get_child_value_hash	(&last_pow_blk, calc_crc32_c("blkHash"), h);
					store_last_pow_hash					(h);
					
				}
			}
			log_message	("loaded last block pow %blkHash%", &last_pow_blk);

			tree_manager_create_node("diff", 0x00000002, &POWSpace);


			if (!node_get_pow_spacing(&last_pow_blk, &POWSpace))
			{
				copy_zone_ref			(&last_pow_blk, &last_blk);
				if (blk_find_last_pow_block(&last_pow_blk, &time))
				{
					hash_t h;
					tree_manager_get_child_value_hash(&last_pow_blk, calc_crc32_c("blkHash"), h);
					store_last_pow_hash(h);
				}
			}

			if(node_get_pow_spacing		(&last_pow_blk,&POWSpace))
			{
				tree_manager_get_child_value_i32	(&last_pow_blk, calc_crc32_c("bits"), &nBits);

				if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("current_pow_diff"), 0x00000002, &bits))
					tree_manager_add_child_node(&nself_node, "current_pow_diff", 0x00000002, &bits);

				tree_manager_write_node_dword		(&bits, 0, nBits);
				block_compute_pow_target			(&POWSpace,&bits);
				release_zone_ref					(&bits);
			}

			tree_manager_get_child_value_str	(&last_pow_blk, calc_crc32_c("blkHash"), chash,65,16);
			




			release_zone_ref				(&POWSpace);
			release_zone_ref				(&last_pow_blk);
		}

		release_zone_ref(&last_blk);
	}
	return 1;
}

__declspec(dllexport) int  node_load_block_indexes()
{

	mem_zone_ref log = { (void *)0x00000000L };
	mem_zone_ref	block_index_node = { (void *)0x00000000L }, time_index_node = { (void *)0x00000000L };
	uint64_t	    height = 0;
	size_t			len;
	unsigned char *	block_index;

	if (get_file("blk_indexes", &block_index, &len) <= 0)
	{
		tree_manager_set_child_value_i64(&nself_node, "block_height", 0);
		return 0;
	}


	height = len / sizeof(hash_t);
	
	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("block_index"), 0x0B001000, &block_index_node))
		tree_manager_add_child_node	(&nself_node, "block_index", 0x0B001000, &block_index_node);

	tree_manager_write_node_data(&block_index_node, block_index, 0, len);
	free_c						(block_index);
	

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("block time"), 0x00000002, &time_index_node))
		tree_manager_add_child_node	(&nself_node, "block time", 0x00000002, &time_index_node);
	
	if (stat_file("blk_times") != 0)
	{
		uint64_t cur,size;

		size = mul64(height, sizeof(unsigned int));

		log_message							("creating block time index ... ", (void *)0x00000000L);
		tree_manager_expand_node_data_ptr(&time_index_node, size, 4);

		cur = 0;
		while (cur < height)
		{
			hash_t hash;
			uint64_t cur_idx;
			struct string blk_path = { (void *)0x00000000L };
			ctime_t ctime;

			cur_idx = mul64(cur, 32);

			if (tree_manager_get_node_hash(&block_index_node, cur_idx, hash))
			{
				char chash[65];
				int  n;
				n = 0;
				while (n < 32)
				{
					chash[n * 2 + 0] = hex_chars[hash[n] >> 4];
					chash[n * 2 + 1] = hex_chars[hash[n] & 0x0F];
					n++;
				}
				chash[64] = 0;
				make_string		(&blk_path, "blks");
				cat_ncstring_p	(&blk_path, chash, 2);
				cat_ncstring_p	(&blk_path, chash + 2, 2);
				cat_cstring_p	(&blk_path, chash);
				cat_cstring		(&blk_path, "_blk");

				if (!get_ftime(blk_path.str, &ctime))
					ctime = 0;

				free_string(&blk_path);
				append_file("blk_times", &ctime, sizeof(unsigned int));
			}
			cur++;
		}
		log_message("block time index created.", (void *)0x00000000L);

	}
	release_zone_ref(&block_index_node);
	release_zone_ref(&time_index_node);
	
	if (get_file("blk_times", &block_index, &len) <= 0) return 0;
	
	tree_manager_find_child_node(&nself_node, calc_crc32_c("block time"), 0x00000002, &time_index_node);
	tree_manager_write_node_data(&time_index_node, block_index, 0, len);
	release_zone_ref(&time_index_node);
	free_c(block_index);

	tree_manager_set_child_value_i64(&nself_node, "block_height", height);

	tree_manager_create_node("log", 0x0A000010, &log);
	tree_manager_set_child_value_i32(&log, "lastblockheight", height);
	log_message("loaded block index, height %lastblockheight%", &log);
	release_zone_ref(&log);
	return 1;
	
}

__declspec(dllexport) int  node_set_script(mem_zone_ref_ptr script)
{
	node_script.zone = script->zone;

	return 1;
}

__declspec(dllexport) int  node_zip_self(struct string *out_data, mem_zone_ref_ptr opts)
{
	mem_zone_ref     conf = { (void *)0x00000000L },mod_def_var = { (void *)0x00000000L }, Assetsfiles = { (void *)0x00000000L };
	struct string	 filePath = { (void *)0x00000000L }, init_data = { (void *)0x00000000L };
	char			 system[32];
	char			 ModPath[16][64];
	char			 AssetsPath[32][64];
	char			 *files[64];
	unsigned int	 mod_idx = 0;
	unsigned int	 block_explorer = 0;
	unsigned int	 wallet = 0;
	int				 Nfiles = 0, nMods = 0, nAssets=0;
	int				 ret;

	if (tree_manager_find_child_node(opts, calc_crc32_c("block_explorer"), 0x00000001, (void *)0x00000000L))
		block_explorer = 1;

	if (tree_manager_find_child_node(opts, calc_crc32_c("rpc_wallet"), 0x00000001, (void *)0x00000000L))
		wallet = 1;

	if (!tree_manager_get_child_value_str(opts, calc_crc32_c("target"), system,0))
		strcpy_cs(system, 32, "windows");
	else if (strcmp_c(system, "linux") !=0 )
		strcpy_cs(system, 32, "windows");
	
	files[Nfiles++] = "nodix.node";
	files[Nfiles++] = "web/nodix.site";
	files[Nfiles++] = "web/templates/address.html";
	files[Nfiles++] = "web/templates/block.html";
	files[Nfiles++] = "web/templates/blocks.html";
	files[Nfiles++] = "web/templates/staking.html";
	files[Nfiles++] = "web/templates/tx.html";
	files[Nfiles++] = "web/templates/wallet.html";
	files[Nfiles++] = "web/templates/transaction.html";
	files[Nfiles++] = "web/templates/footer.html";
	files[Nfiles++] = "web/templates/menu.html";
	files[Nfiles++] = "web/templates/node.html";
	files[Nfiles++] = "web/templates/services.html";
	files[Nfiles++] = "web/templates/application.html";
	files[Nfiles++] = "web/templates/applications.html";
		
	if (tree_manager_create_node("assets", 0x09000001, &Assetsfiles))
	{
		mem_zone_ref	 my_list = { (void *)0x00000000L };
		mem_zone_ref_ptr file = (void *)0x00000000L;

		node_get_service_script_assets("http_service", "web/nodix.site", &Assetsfiles);
		for (tree_manager_get_first_child(&Assetsfiles, &my_list, &file); ((file != (void *)0x00000000L) && (file->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &file))
		{
			char relp[64];
			if (!tree_manager_get_node_str(file, 0, relp, 64, 0))continue;

			strcpy_cs					(AssetsPath[nAssets], 64, "web");
			strcat_cs					(AssetsPath[nAssets], 64, relp);

			files[Nfiles++] = AssetsPath[nAssets++];
		}
		release_zone_ref(&Assetsfiles);
	}

	files[Nfiles++] = "web/assets/js/webGL/J3DI.js";
	files[Nfiles++] = "web/assets/js/webGL/J3DIMath.js";
	files[Nfiles++] = "web/assets/js/webGL/webgl-utils.js";
	
	files[Nfiles++] = "web/assets/js/tinymce/tinymce.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/themes/modern/theme.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/autolink/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/link/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/image/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/lists/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/charmap/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/print/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/preview/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/anchor/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/pagebreak/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/spellchecker/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/searchreplace/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/hr/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/wordcount/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/visualblocks/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/visualchars/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/code/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/fullscreen/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/media/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/nonbreaking/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/save/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/table/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/insertdatetime/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/contextmenu/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/directionality/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/smileys/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/template/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/textcolor/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/noneditable/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/paste/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/plugins/advlist/plugin.min.js";
	files[Nfiles++] = "web/assets/js/tinymce/skins/lightgray/skin.min.css";
	files[Nfiles++] = "web/assets/js/tinymce/skins/lightgray/content.min.css";
	files[Nfiles++] = "web/assets/js/tinymce/skins/lightgray/fonts/tinymce.woff";
	
	files[Nfiles++] = "web/assets/js/colorpicker/colorpicker.js";
	files[Nfiles++] = "web/assets/css/colorpicker/colorpicker.css";
	files[Nfiles++] = "web/assets/img/Nodix.svg";
	files[Nfiles++] = "web/assets/img/colorpicker_background.png";
	files[Nfiles++] = "web/assets/img/mod.gif";
	files[Nfiles++] = "web/assets/img/proc.gif";


	if ((block_explorer) || (wallet))
	{
		files[Nfiles++] = "web/assets/css/plugins/blocks.css";
		files[Nfiles++] = "web/assets/js/blocks.js";
	}

	if (block_explorer)
	{
		files[Nfiles++] = "block-explorer.url";
		files[Nfiles++] = "web/assets/js/plugins/datepicker.js";

		files[Nfiles++] = "modz/block_explorer.tpo";
	}

	if (wallet)
	{
		files[Nfiles++] = "wallet.url";
		files[Nfiles++] = "web/assets/js/ecdsa_bundle.js";
		files[Nfiles++] = "web/assets/js/keys.js";
		files[Nfiles++] = "web/assets/js/md5.min.js";
		files[Nfiles++] = "web/assets/js/jsSHA-2.2.0/src/sha_dev.js";

		files[Nfiles++] = "modz/rpc_wallet.tpo";
		files[Nfiles++] = "modz/anon_rpc.tpo";
	}

	files[Nfiles++] = "modz/libbase.tpo";

	while (tree_node_find_child_by_type(&node_script, 0x08000008, &mod_def_var, mod_idx++))
	{
		tree_manager_get_child_value_str(&mod_def_var, calc_crc32_c("file"), ModPath[nMods], 64, 0);
		files[Nfiles++] = ModPath[nMods++];

		release_zone_ref(&mod_def_var);
	}

	if (resolve_script_var(&node_script, (void *)0x00000000L, "configuration", 0xFFFFFFFF, &conf, (void *)0x00000000L))
	{
		mod_idx = 0;
		while (tree_node_list_child_by_type(&conf, 0x08000008, &mod_def_var, mod_idx++))
		{
			tree_manager_get_child_value_str(&mod_def_var, calc_crc32_c("file"), ModPath[nMods], 64, 0);
			files[Nfiles++] = ModPath[nMods++];

			release_zone_ref(&mod_def_var);

		}
		release_zone_ref(&conf);
	}


	if (!strcmp_c(system, "windows"))
	{
		get_file	("winbin.zip", &init_data.str, &init_data.size);
		init_data.len = init_data.size;
	}
	else
	{
		files[Nfiles++] = "launcher";
		files[Nfiles++] = "libcon.so";
		init_string	(&init_data);
	}
	
	ret=do_zip("nodix.zip", &init_data,files, Nfiles, out_data);

	free_string(&init_data);

	return ret;
}

__declspec(dllexport) int  node_get_script_modules(mem_zone_ref_ptr modules)
{
	mem_zone_ref     mod_def_var = { (void *)0x00000000L }, conf = { (void *)0x00000000L };
	unsigned int	 mod_idx = 0;

	if (node_script.zone == (void *)0x00000000L)return 0;
	if (node_script.zone == (void *)0xDEADBEEFLL)return 0;

	tree_remove_children(modules);

	while (tree_node_find_child_by_type(&node_script, 0x08000008, &mod_def_var, mod_idx++))
	{
		tree_manager_node_add_child(modules, &mod_def_var);
		release_zone_ref(&mod_def_var);
	}

	if (resolve_script_var(&node_script, (void *)0x00000000L, "configuration", 0xFFFFFFFF, &conf, (void *)0x00000000L))
	{
		mod_idx = 0;
		while (tree_node_list_child_by_type(&conf, 0x08000008, &mod_def_var, mod_idx++))
		{
			tree_manager_node_add_child(modules, &mod_def_var);
			release_zone_ref(&mod_def_var);
		}
		release_zone_ref(&conf);
	}

	return 1;
}


__declspec(dllexport) int  node_get_script_msg_handlers(mem_zone_ref_ptr handlers)
{
	mem_zone_ref     handler_proc = { (void *)0x00000000L };
	unsigned int	 proc_idx = 0;

	if (node_script.zone == (void *)0x00000000L)return 0;
	if (node_script.zone == (void *)0xDEADBEEFLL)return 0;

	tree_remove_children(handlers);
	while (tree_node_find_child_by_type(&node_script, 0x08000080, &handler_proc, proc_idx++))
	{
		mem_zone_ref zone = { (void *)0x00000000L };
		const char *name = tree_mamanger_get_node_name(&handler_proc);

		if (tree_manager_create_node(name, 0x08000080, &zone))
		{
			struct string code = { (void *)0x00000000L };
			tree_manager_get_node_istr			(&handler_proc, 0, &code, 0);
			tree_manager_set_child_value_str	(&zone, "name", name);
			tree_manager_set_child_value_vstr	(&zone, "code", &code);
			
			free_string							(&code);
		}
		tree_manager_node_add_child	(handlers, &zone);

		release_zone_ref(&zone);
		release_zone_ref(&handler_proc);
	}
	return 1;
}



__declspec(dllexport) int  node_init_self(mem_zone_ref_ptr self_node)
{
	
	mem_zone_ref		p2p_node = { (void *)0x00000000L }, mempool = { (void *)0x00000000L };;

	nself_node.zone		= (void *)0x00000000L;
	if (node_script.zone == (void *)0xDEADBEEFLL)node_script.zone	= (void *)0x00000000L;
	
	copy_zone_ref		(&nself_node, self_node);
	dump_self			();
		

	create_dir			("node");

	tree_manager_find_child_node	(&nself_node, calc_crc32_c("mempool"), 0x0B004000, &mempool);
	tree_manager_write_node_dword	(&mempool, 0, 0);
	release_zone_ref				(&mempool);


	tree_manager_add_child_node		(&nself_node, "tmp files", 0x09000001, (void *)0x00000000L);

	mining_lock = 0;
	mempool_lock = 0;


	if (tree_manager_find_child_node(&nself_node, calc_crc32_c("p2p_addr"), 0x0B000040, &p2p_node))
	{
		char			ip[32];
		uint64_t		services;
		struct con		*listen_con;
		unsigned int	usePnp;
		unsigned short	node_port = 0;
		
		tree_manager_get_child_value_i64(&p2p_node, calc_crc32_c("services")	, &services);
		tree_manager_get_child_value_str(&p2p_node, calc_crc32_c("addr")		, ip, 32, 0);
		tree_manager_get_child_value_i16(&p2p_node, calc_crc32_c("port")		, &node_port);

		listen_con = open_port(ip, node_port);
		if (listen_con != (void *)0x00000000L)
		{
			mem_zone_ref log = { (void *)0x00000000L };

			tree_manager_set_child_value_ptr(&nself_node, "p2p_con", listen_con);
			tree_manager_set_child_value_i32(&nself_node, "p2p_status", 1);

			tree_manager_create_node("log", 0x0A000010, &log);
			tree_manager_set_child_value_i32(&log, "port"	 , node_port);
			tree_manager_set_child_value_str(&log, "addr", ip);
			log_message("node port %port% open @ '%addr%'", &log);
			release_zone_ref(&log);


			if (!tree_manager_get_child_value_i32(&nself_node, calc_crc32_c("uPnP"), &usePnp))
				usePnp = 0;

			if (usePnp!=0)
			{
				struct string port_str = { (void *)0x00000000L };
				tree_manager_get_child_value_istr(&p2p_node, calc_crc32_c("port"), &port_str,10);
				broadcastDiscovery();
				forwardPort(&port_str);
				free_string(&port_str);
			}
		}
		else
		{
			mem_zone_ref log = { (void *)0x00000000L };
			tree_manager_create_node			("log", 0x0A000010, &log);
			tree_manager_set_child_value_i32	(&log, "port", node_port);
			log_message							("unable to open p2p port %port%", &log);
			release_zone_ref					(&log);
		}
		release_zone_ref(&p2p_node);
	}
	
	return 1;
}

__declspec(dllexport) int  node_is_next_block(mem_zone_ref_const_ptr header)
{
	hash_t		 prevHash, lastHash;
	mem_zone_ref lastBlk = { (void *)0x00000000L };
	int			 ret=1;
	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("last_block"), 0x0B000800, &lastBlk))return 0;
	tree_manager_get_child_value_hash(header, calc_crc32_c("prev"), prevHash);
	if (!tree_manager_get_child_value_hash(&lastBlk, calc_crc32_c("blkHash"), lastHash))
	{
		compute_block_hash(&lastBlk, lastHash);
		tree_manager_set_child_value_hash(&lastBlk, "blkHash", lastHash);

	}
	ret = (memcmp_c(lastHash, prevHash, sizeof(hash_t)) == 0) ? 1:0;
	release_zone_ref(&lastBlk);

	return ret;
}



__declspec(dllexport) int  node_add_block_index(hash_t hash,unsigned int time)
{
	mem_zone_ref	block_index_node = { (void *)0x00000000L };
	uint64_t		nblks,blkidx,nxtblk;
	unsigned int	ntries=3;

	if (!tree_manager_get_child_value_i64(&nself_node, calc_crc32_c("block_height"), &nblks))
	{
		log_output("no blk height \n");
		return 0;
	}

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("block_index"), 0x0B001000, &block_index_node))
		tree_manager_add_child_node(&nself_node, "block_index", 0x0B001000, &block_index_node);

	if (block_index_node.zone == (void *)0x00000000L)
	{
		log_output("no blk idx \n");
		return 0;
	}

	blkidx = mul64(nblks, sizeof(hash_t));

	if (!tree_manager_expand_node_data_ptr(&block_index_node, blkidx, sizeof(hash_t)))
	{
		mem_zone_ref log = { (void *)0x00000000L };
		if (tree_manager_create_node("log", 0x0A000010, &log))
		{
			tree_manager_set_child_value_i32(&log, "nblks", nblks);
			log_message						("could not expand block index to %nblks%", &log);
			release_zone_ref				(&log);
		}
		release_zone_ref(&block_index_node);
		return 0;
	}

	
	tree_manager_write_node_hash		(&block_index_node, blkidx, hash);
	release_zone_ref					(&block_index_node);

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("block time"), 0x00000002, &block_index_node))
		tree_manager_add_child_node(&nself_node, "block time", 0x00000002, &block_index_node);

	blkidx = mul64(nblks, sizeof(unsigned int));

	if (!tree_manager_expand_node_data_ptr(&block_index_node, blkidx, sizeof(unsigned int)))
	{
		mem_zone_ref log = { (void *)0x00000000L };
		if (tree_manager_create_node("log", 0x0A000010, &log))
		{
			tree_manager_set_child_value_i32(&log, "nblks", nblks);
			log_message						("could not expand block time index to %nblks%", &log);
			release_zone_ref				(&log);
		}
		release_zone_ref(&block_index_node);
		return 0;
	}

	
	tree_manager_write_node_dword		(&block_index_node, blkidx, time);
	release_zone_ref					(&block_index_node);

	nxtblk=nblks+1;

	tree_manager_set_child_value_i64	(&nself_node, "block_height",nxtblk);
	append_file							("blk_indexes", hash , 32);
	append_file							("blk_times"  , &time, 4);
	return 1;
}

__declspec(dllexport) int  node_set_last_block(mem_zone_ref_ptr header)
{
	hash_t				h,pow;
	mem_zone_ref		last_blk = { (void *)0x00000000L };
	unsigned int		t,time;

	tree_manager_get_child_value_hash(header, calc_crc32_c("blkHash"), h);
	tree_manager_get_child_value_i32 (header, calc_crc32_c("time"), &t);



	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("last_block"), 0x0B000800, &last_blk))
		tree_manager_add_child_node(&nself_node, "last_block", 0x0B000800, &last_blk);

	tree_manager_copy_children_ref		(&last_blk, header);
	release_zone_ref					(&last_blk);
	
	if (tree_manager_get_child_value_hash(header, calc_crc32_c("blk pow"), pow))
	{
		if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("lastPOWBlk"), 0x0B000800, &last_blk))
			tree_manager_add_child_node(&nself_node, "lastPOWBlk", 0x0B000800, &last_blk);

		tree_manager_copy_children_ref(&last_blk, header);
		release_zone_ref(&last_blk);
		store_last_pow_hash(h);
	}
	else
	{
		if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("lastPOSBlk"), 0x0B000800, &last_blk))
			tree_manager_add_child_node(&nself_node, "lastPOSBlk", 0x0B000800, &last_blk);

		tree_manager_copy_children_ref(&last_blk, header);
		release_zone_ref(&last_blk);
		store_last_pos_hash(h);
	}

	if (!node_add_block_index(h, t))
	{
		log_output("unable to add block index\n");
		return 0;
	}

	tree_manager_get_child_value_i32(header, calc_crc32_c("time"), &time);
	tree_manager_set_child_value_i32(&nself_node, "last_block_time", time);
	

	log_message						("new blockchain height : %block_height%", &nself_node);

	return 1;
}





int new_peer_node(struct con *p2p_con, const struct host_def *newDef,unsigned int entrant)
{
	ipv4_t					node_addr;
	mem_zone_ref			log = { (void *)0x00000000L }, new_node = { (void *)0x00000000L }, peer_nodes = { (void *)0x00000000L };
	
	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("peer_nodes"), 0x0B000001, &peer_nodes))return 0;

	if (tree_manager_get_node_num_children(&peer_nodes) >= 10)
	{
		log_output("max peer node reached\n");
		release_zone_ref(&peer_nodes);
		return 0;
	}
	tree_manager_create_node("log", 0x0A000010, &log);
	tree_manager_set_child_value_i32(&log, "port", newDef->port);
	tree_manager_set_child_value_str(&log, "hostname", newDef->host.str);
	log_message("connected to node @%hostname%:%port%", &log);
	release_zone_ref(&log);
	
	if (!tree_manager_create_node(newDef->host.str, 0x0B000002, &new_node))
	{
		release_zone_ref(&peer_nodes);
		log_output		("could not create new node\n");
		return 0;
	}

	

	get_con_saddr(p2p_con, node_addr);

	tree_manager_add_child_node		(&new_node, "queried_hashes", 0x0B003000, (void *)0x00000000L);
	tree_manager_add_child_node		(&new_node, "send queue", 0x0B000004, (void *)0x00000000L);
	tree_manager_add_child_node		(&new_node, "peer_addrs", 0x0B000020, (void *)0x00000000L);

	tree_manager_set_child_value_ptr(&new_node, "p2p_con", p2p_con);
	add_bitcore_addr				(&new_node, node_addr, newDef->port, 0);
	tree_manager_set_child_value_i32(&new_node, "p2p_status", 1);
	tree_manager_set_child_value_i32(&new_node, "need_recon", 0);
	
	tree_manager_set_child_value_si64(&new_node, "last_ping" , 0);
	tree_manager_set_child_value_si64(&new_node, "last_pong", 0);
	tree_manager_set_child_value_si64(&new_node, "next_pong", 0);
	tree_manager_set_child_value_si64(&new_node, "ping_delay", 0);


	tree_manager_set_child_value_i32(&new_node, "entrant", entrant);
	tree_manager_set_child_value_i32(&new_node, "synching", 0);
	tree_manager_node_add_child(&peer_nodes, &new_node);

	if (entrant)
	{
		queue_version_message(&new_node);
		queue_mempool_message(&new_node);
	}

	release_zone_ref(&new_node);
	release_zone_ref(&peer_nodes);

	return 1;
}


__declspec(dllexport) int  connect_peer_node(mem_zone_ref_ptr node_def)
{
	char				node_hostname[256];
	mem_zone_ref		log = { (void *)0x00000000L };
	mem_zone_ref		new_node_addr = { (void *)0x00000000L }, peer_nodes = { (void *)0x00000000L };
	struct con			*node_con;
	struct host_def		*host;
	unsigned short		node_port;
	unsigned int		n_peers;
	int					ret ;

	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("peer_nodes"), 0x0B000001, &peer_nodes))return 0;
	n_peers = tree_manager_get_node_num_children(&peer_nodes);
	release_zone_ref(&peer_nodes);
	if (n_peers >= 10)
	{
		log_output("max peer node reached\n");
		return 0;
	}

	if (!tree_manager_get_child_value_str(node_def, calc_crc32_c("host"), node_hostname, 256, 0))
		tree_manager_get_child_value_str(node_def, calc_crc32_c("addr"), node_hostname, 256, 0);

	tree_manager_get_child_value_i16(node_def, calc_crc32_c("port"), &node_port);

	host = make_host_def(node_hostname, node_port);

	tree_manager_create_node("log", 0x0A000010, &log);
	tree_manager_set_child_value_i32(&log, "port", host->port);
	tree_manager_set_child_value_str(&log, "hostname", host->host.str);
	log_message("connecting to node @%hostname%:%port%", &log);
	release_zone_ref(&log);

	node_con = do_connect(host);
	if ((get_con_error(node_con)->len > 0) && (get_con_error(node_con)->str != (void *)0x00000000L))
	{
		tree_manager_create_node			("log", 0x0A000010, &log);
		tree_manager_set_child_value_i32	(&log, "port", host->port);
		tree_manager_set_child_value_str	(&log, "hostname", host->host.str);
		tree_manager_set_child_value_str	(&log, "error", get_con_error(node_con)->str);
		log_message							("failed to connect seed node @%hostname%:%port% error :'%error%' ", &log);
		release_zone_ref					(&log);
		ret = 0;
	}
	else
		ret = new_peer_node(node_con,host,0);

	if (!ret)con_close(node_con);

	free_host_def	 (host);
	return ret;
}



__declspec(dllexport) int  node_check_new_connections()
{
	struct con			*listen_con,*new_con;
	unsigned int		status;

	if (!tree_manager_get_child_value_i32(&nself_node, calc_crc32_c("p2p_status"), &status))return 0;
	if (!tree_manager_get_child_value_ptr(&nself_node, calc_crc32_c("p2p_con"), listen_con))return 0;

	while ((new_con = do_get_incoming(listen_con, 10)) != (void *)0x00000000)
	{
		mem_zone_ref log = { (void *)0x00000000L };
		const struct host_def	*newDef;

		newDef = get_con_hostd(new_con);

		tree_manager_create_node			("log", 0x0A000010, &log);
		tree_manager_set_child_value_i32	(&log, "port", newDef->port);
		tree_manager_set_child_value_str	(&log, "hostname", newDef->host.str);
		log_message							("new connection from node @%hostname%:%port%", &log);
		release_zone_ref					(&log);

		new_peer_node						(new_con, newDef,1);
	

	}

	return 1;


}


__declspec(dllexport) int  node_rewrite_txs(uint64_t nums)
{
	mem_zone_ref block_index_node = { (void *)0x00000000L }, time_index_node = { (void *)0x00000000L }, blk_hdr = { (void *)0x00000000L }, log = { (void *)0x00000000L };
	uint64_t	start,cur,lb,last_log,cur_idx;
	hash_t		null_hash;
	unsigned int last_block_time;
	unsigned int *time_ptr;
	unsigned char *bh_ptr;
	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("block_index"), 0x0B001000, &block_index_node))return 0;
	
	if (!tree_manager_find_child_node(&nself_node, calc_crc32_c("block time"), 0x00000002, &time_index_node))
		tree_manager_add_child_node(&nself_node, "block time", 0x00000002, &time_index_node);

	lb		= get_last_block_height();

	
	if (nums==0)
		start = 1;
	else
		start = lb - nums;

	memset_c(null_hash, 0, sizeof(hash_t));
	

	
	tree_manager_create_node		("log", 0x0A000010, &log);
	tree_manager_set_child_value_i32(&log, "start", start);
	tree_manager_set_child_value_i32(&log, "lb", lb);
	log_message						("rebuilding blocks tx from %start% / %lb% ", &log);
	release_zone_ref				(&log);

	
	cur					= start;
	last_log			= cur;
	last_block_time		= 0;
	while (cur < lb)
	{
		char			chash[65];
		struct string	blk_path = { (void *)0x00000000L };
		mem_zone_ref	txs={(void *)0x00000000L};
		size_t			n_txs;
		unsigned int	block_time;
		int				error ;
		uint64_t		bheight;

		if ((cur - last_log) >= 100)
		{
			tree_manager_create_node("log", 0x0A000010, &log);
			tree_manager_set_child_value_i64(&log, "cur", cur);
			tree_manager_set_child_value_i64(&log, "lb", lb);
			log_message("processing block %cur% / %lb%", &log);
			release_zone_ref(&log);





			last_log = cur;
		}

		cur_idx = mul64(cur, 32);

		tree_manager_get_node_str(&block_index_node, cur_idx, chash, 65, 16);
		if (!load_blk_hdr(&blk_hdr, chash))
		{
			log_output("blk [");
			log_output(chash);
			log_output("] not found\n");
			break;
		}
		
	
		tree_manager_get_child_value_i64(&blk_hdr,calc_crc32_c("height"),&bheight);

		if (bheight != (cur + 1))
		{
			log_output("blk height mismatch\n");
			break;
		}

		
		if (cur > 0)
		{
			hash_t		ph, pbh;
			uint64_t	uidx;

			uidx = mul64((cur - 1), 32);

			if (!tree_manager_get_child_value_hash(&blk_hdr, calc_crc32_c("prev"), pbh))
			{
				log_output("blk prev hash fail\n");
				break;
			}
			tree_manager_get_node_hash			(&block_index_node, uidx, ph);
			if (memcmp_c(pbh, ph, 32))
			{
				log_output("blk prev hash mismatch\n");
				break;
			}
		}
		if (!tree_manager_get_child_value_i32(&blk_hdr, calc_crc32_c("time"), &block_time))
		{
			log_output("blk time fail\n");
			break;
		}
		if (block_time <= last_block_time)
		{
			log_output("blk time mismatch\n");
			break;
		}
		
		

		make_string		(&blk_path, "blks");
		cat_ncstring_p	(&blk_path, chash + 0, 2);
		cat_ncstring_p	(&blk_path, chash + 2, 2);
		cat_cstring_p	(&blk_path, chash);
		cat_cstring		(&blk_path, "_blk");
		set_ftime		(blk_path.str, block_time);
		free_string		(&blk_path);


		last_block_time = block_time;
		n_txs			= 0;
		error			= 0;
		if(tree_manager_create_node("txs",0x0B004000,&txs))
		{
		
			if(load_blk_txs	(chash,&txs))
			{
				hash_t				merkleRoot, merkle;
				mem_zone_ref		my_list = { (void *)0x00000000L };
				mem_zone_ref_ptr	tx=(void *)0x00000000L;
			
				build_merkel_tree					(&txs, merkleRoot);
				tree_manager_get_child_value_hash	(&blk_hdr, calc_crc32_c("merkle_root"), merkle);
				
				if (memcmp_c(merkle, merkleRoot, sizeof(hash_t)))
				{
					build_merkel_tree(&txs, merkleRoot);
					log_output("blk merkle mismatch\n");
					release_zone_ref(&txs);
					break;
				}
				
				n_txs=tree_manager_get_node_num_children(&txs);
				for (tree_manager_get_first_child(&txs, &my_list, &tx); ((tx != (void *)0x00000000L) && (tx->zone != (void *)0x00000000L)); tree_manager_get_next_child(&my_list, &tx))
				{
					
					if (!store_tx_inputs(tx))
					{
						error = 1;
						log_output("store txin error \n");
						dec_zone_ref(tx);
						dec_zone_ref(&my_list);
						break;
					}

					
					if(!store_tx_outputs(tx))
					{
						error = 1;
						log_output("store txout error \n");
						dec_zone_ref(tx);
						dec_zone_ref(&my_list);
						break;
					}
					
				}
			}
			release_zone_ref(&txs);
		}
		
		if (error != 0)
			break;

		if (n_txs == 0)
		{
			log_output("blk zero tx count\n");
			break;
		}

		cur++;
		release_zone_ref(&blk_hdr);
	}
	release_zone_ref(&blk_hdr);

	if (cur < lb)
	{
		tree_manager_create_node("log", 0x0A000010, &log);
		tree_manager_set_child_value_i64(&log, "cur", cur);
		tree_manager_set_child_value_i64(&log, "lb", lb);
		log_message("truncating chain to %cur% / %lb% ", &log);
		release_zone_ref(&log);
		node_truncate_chain(cur);
	}
	
	time_ptr = (unsigned int *) tree_mamanger_get_node_data_ptr(&time_index_node , 0);
	bh_ptr   = (unsigned char *)tree_mamanger_get_node_data_ptr(&block_index_node, 0);

	cur_idx = mul64(cur, sizeof(unsigned int));
	put_file("blk_times", time_ptr, cur_idx);

	cur_idx = mul64(cur, sizeof(hash_t));
	put_file("blk_indexes", bh_ptr, cur_idx);






































































































































#line 4492 "node.c"

	release_zone_ref(&block_index_node);
	release_zone_ref(&time_index_node);
	return 1;
}

__declspec(dllexport) int  reset_moneysupply()
{
	uint64_t cur = 0;
	put_file("supply", &cur, sizeof(uint64_t));
	return 1;
}
__declspec(dllexport) int  add_moneysupply(uint64_t amount)
{
	unsigned char *data;
	size_t len;
	uint64_t cur = 0;

	if (get_file("supply", &data, &len)>0)
	{
		if (len >= sizeof(uint64_t))
			cur = *((uint64_t *)data);
		free_c(data);
	}
	cur += amount;
	put_file("supply", &cur, sizeof(uint64_t));

	return 1;
}




__declspec(dllexport) int  sub_moneysupply(uint64_t amount)
{
	unsigned char *data;
	size_t len;
	uint64_t cur = 0;

	if (get_file("supply", &data, &len)>0)
	{
		if (len >= sizeof(uint64_t))
			cur = *((uint64_t *)data);
		free_c(data);
	}
	if (cur > amount)
		cur -= amount;
	else
		cur = 0;

	put_file("supply", &cur, sizeof(uint64_t));

	return 1;
}

__declspec(dllexport) int  add_money_supply(mem_zone_ref_ptr nAmount)
{
	uint64_t amount;
	if (!tree_mamanger_get_node_qword(nAmount, 0, &amount))return 0;
	return add_moneysupply(amount);
}

__declspec(dllexport) int  sub_money_supply(mem_zone_ref_ptr nAmount)
{
	uint64_t amount;
	if (!tree_mamanger_get_node_qword(nAmount, 0, &amount))return 0;
	return sub_moneysupply(amount);
}

__declspec(dllexport) int  node_aquire_mining_lock()
{
	while (!compare_z_exchange_c(&mining_lock, 1)){}
	return 1;
}


__declspec(dllexport) int  node_release_mining_lock()
{
	mining_lock = 0;
	return 1;
}

__declspec(dllexport) int  node_aquire_mempool_lock(mem_zone_ref_ptr mempool)
{
	while (!compare_z_exchange_c(&mempool_lock, 1)){}


	if (mempool!=(void *)0x00000000L)
		tree_manager_find_child_node(&nself_node, calc_crc32_c("mempool"), 0x0B004000, mempool);

	return 1;
}

__declspec(dllexport) int  node_release_mempool_lock()
{
	mempool_lock = 0;

	return 1;
}
__declspec(dllexport) int  node_create_pow_block(mem_zone_ref_ptr newBlock, btc_addr_t coinbaseAddr)
{
	char			chash[65];

	hash_t			block_hash, merkle;
	mem_zone_ref	lpow = { (void *)0x00000000L };
	unsigned int	version, time, bits, n;
	uint64_t		height, reward;

	tree_manager_find_child_node		(&nself_node, calc_crc32_c("last_block"), 0x0B000800, &lpow);
	tree_manager_get_child_value_hash	(&lpow, calc_crc32_c("blkHash"), block_hash);
	release_zone_ref					(&lpow);

	


	tree_manager_get_child_value_i32	(&nself_node, calc_crc32_c("current_pow_diff")	, &bits);

	get_block_version					(&version);

	n = 0;
	while (n<32)
	{
		chash[n * 2 + 0] = hex_chars[block_hash[n] >> 4];
		chash[n * 2 + 1] = hex_chars[block_hash[n] & 0x0F];
		n++;
	}
	chash[64] = 0;

	get_blk_height	(chash, &height);
	get_blockreward(height, &reward);

	time = get_time_c();

	if (tree_manager_create_node("block", 0x0B000800, newBlock))
	{
		mem_zone_ref txs = { (void *)0x00000000L };
		struct string null_str = { 0 };
		unsigned char vntx[2] = { 0 };

		tree_manager_set_child_value_hash(newBlock, "prev", block_hash);
		tree_manager_set_child_value_i32(newBlock, "version", version);
		tree_manager_set_child_value_i32(newBlock, "time", time);
		tree_manager_set_child_value_i32(newBlock, "bits", bits);
		tree_manager_set_child_value_i32(newBlock, "nonce", 0);
		tree_manager_set_child_value_i64(newBlock, "height", height);
		tree_manager_set_child_value_vint(newBlock, "ntx", vntx);
		tree_manager_set_child_value_vstr(newBlock, "signature", &null_str);


		if (tree_manager_add_child_node(newBlock, "txs", 0x0B004000, &txs))
		{
			hash_t			null_hash = { 0 };
			mem_zone_ref	cbtx = { (void *)0x00000000L }, script_node = { (void *)0x00000000L };
			struct string	coinbasescript = { (void *)0x00000000L }, oscript = { (void *)0x00000000L };
			char			null = 0;
			char			script[8];
			
			coinbasescript.str	= script;
			coinbasescript.len	= 4;
			coinbasescript.size = 4;

			script[0] = 3;
			*((unsigned int *)(script + 1)) = height;

			new_transaction				(&cbtx, time);
			tx_add_input				(&cbtx, null_hash, 0xFFFFFFFF, &coinbasescript);

			tree_manager_create_node	("script",0x0B200000,&script_node);

			create_p2sh_script			(coinbaseAddr, &script_node);
			serialize_script			(&script_node, &oscript);
			release_zone_ref			(&script_node);

			tx_add_output				(&cbtx, reward,&oscript);
			free_string					(&oscript);

			tree_manager_node_add_child	(&txs, &cbtx);

			build_merkel_tree			(&txs, merkle);
			release_zone_ref			(&txs);
			release_zone_ref			(&cbtx);

		}
		else
			memset_c(merkle, 0, sizeof(hash_t));

		tree_manager_set_child_value_hash (newBlock, "merkle_root", merkle);
		compute_block_hash				  (newBlock, block_hash);
		tree_manager_set_child_value_bhash(newBlock, "blkHash", block_hash);

	}
	return 1;

}
