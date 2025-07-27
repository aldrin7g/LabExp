mov dptr,#4500H
movx a,@dptr
mov b,a
inc dptr
movx a,@dptr
subb a,b
inc dptr
movx @dptr,a
end