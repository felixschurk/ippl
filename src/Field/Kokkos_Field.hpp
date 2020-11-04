namespace ippl {
    namespace detail {
        template <typename T, unsigned Dim, class M, class C>
        struct isExpression<Field<T, Dim, M, C>> : std::true_type {};
    }

    //////////////////////////////////////////////////////////////////////////
    // A default constructor, which should be used only if the user calls the
    // 'initialize' function before doing anything else.  There are no special
    // checks in the rest of the Field methods to check that the Field has
    // been properly initialized
    template<class T, unsigned Dim, class M, class C>
    Field<T,Dim,M,C>::Field()
    : BareField<T, Dim>()
    , mesh_m(nullptr)
    { }

    //////////////////////////////////////////////////////////////////////////
    // Constructors which include a Mesh object as argument
    template<class T, unsigned Dim, class M, class C>
    Field<T,Dim,M,C>::Field(Mesh_t& m, Layout_t& l)
    : BareField<T,Dim>(l)
    , mesh_m(&m)
    { }


    //////////////////////////////////////////////////////////////////////////
    // Initialize the Field, also specifying a mesh
    template<class T, unsigned Dim, class M, class C>
    void Field<T,Dim,M,C>::initialize(Mesh_t& m, Layout_t& l) {
        BareField<T,Dim>::initialize(l);
        mesh_m = &m;
    }


    /*!
     * User interface of gradient in three dimensions.
     * @param u field
     */
    template <typename T, unsigned Dim, class M, class C>
    KOKKOS_INLINE_FUNCTION
    detail::meta_grad<Field<T, Dim, M, C>> grad(const Field<T, Dim, M, C>& u) {
        return detail::meta_grad<Field<T, Dim, M, C>>(u);
    }


    /*!
     * User interface of divergence in three dimensions.
     * @param u field
     */
    template <typename T, unsigned Dim, class M, class C>
    KOKKOS_INLINE_FUNCTION
    detail::meta_div<Field<T, Dim, M, C>> div(const Field<T, Dim, M, C>& u) {
        return detail::meta_div<Field<T, Dim, M, C>>(u);
    }


    /*!
     * User interface of Laplacian in three dimensions.
     * @param u field
     */
    template <typename T, unsigned Dim, class M, class C>
    KOKKOS_INLINE_FUNCTION
    detail::meta_laplace<Field<T, Dim, M, C>> laplace(const Field<T, Dim, M, C>& u) {
        return detail::meta_laplace<Field<T, Dim, M, C>>(u);
    }
}
