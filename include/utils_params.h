#ifndef UTILS_PARAMS_H
#define UTILS_PARAMS_H

#include "btfast.h"         // strategy_t, parameters_t, param_ranges_t


//#include <queue>            // std::queue


// Set of Utility functions, for handling parameters containers


namespace utils_params {

    // --------------------------------------------------------------------- //
    /*!  Print content of parameters_t type
        [ ("p1", 2), ("p2", 7), ... ]
    */
    void print_parameters_t( const parameters_t& p );

    // --------------------------------------------------------------------- //
    /*!  Print content of strategy_t type
        [ ("metric1", 2.3), ..., ("p1", 2), ("p2", 7), ... ]
    */
    void print_strategy_t( const strategy_t& s );

    // --------------------------------------------------------------------- //
    /*!  Print content of vector of parameters_t type
        [ [ ("p1", 2), ("p2", 7), ... ],
          [ ("p1", 4), ("p2", 11), ... ], ... ]
    */
    void print_parameters_t_vector( const std::vector<parameters_t>& v );

    // --------------------------------------------------------------------- //
    /*!  Print content of vector of strategy_t type
        [ [ ("p1", 2), ("p2", 7), ... ],
          [ ("p1", 4), ("p2", 11), ... ], ... ]
    */
    void print_strategy_t_vector( const std::vector<strategy_t>& v );

    // --------------------------------------------------------------------- //
    /*!  Print content of param_ranges_t type
        [ ("p1", [10]), ("p2", [2,4,6,8]), ... ]
    */
    void print_param_ranges_t( const param_ranges_t& par_range );


    // --------------------------------------------------------------------- //
    /*!  From vector v (as returned by utils_fileio::read_param_file() ),

            v =  [ ("p1", [10]), ("p2", [2,4,6,8]), ... ]

         extract first element of std::vector<int>:

            [ ("p1", 10), ("p2", 2), ... ]

         Used to get single set of parameter values read from XML:
            for <Input> parameters:     single fixed value
            for <OptRange> parameters:  start value only
    */
    parameters_t single_parameter_combination( const param_ranges_t &v );

    // --------------------------------------------------------------------- //
    /*!  From vector v (as returned by utils_fileio::read_param_file() ),

            v =  [ ("p1", [10]), ("p2", [2,4,6,8]), ... ]

         return Cartesian product of all parameter combinations

            [ [("p1", 10), ("p2", 2), ...], [("p1", 10), ("p2", 4), ...] ]
    */
    std::vector<parameters_t> cartesian_product( param_ranges_t &v );

    // --------------------------------------------------------------------- //
    /*!  Extract only the parameter values from all strategies in 'source'
         (ignoring the entries with performance metrics)
         and cast them double -> int. Copy the result into 'dest'.
    */
    void extract_parameters_from_all_strategies(
                                        const std::vector<strategy_t> &source,
                                        std::vector<parameters_t> &dest );

    // --------------------------------------------------------------------- //
    /*!  Extract only the parameter values from strategy 'source'
         (ignoring the entries with performance metrics)
         and cast them double -> int. Copy the result into 'dest'.
    */
    void extract_parameters_from_single_strategy( const strategy_t &source,
                                                   parameters_t &dest );


    // --------------------------------------------------------------------- //
    //  Extract only the performance metrics values from strategy 'source'
    //   (ignoring the entries with parameters metrics)
    //   and store them into vector 'dest'.
    void extract_metrics_from_single_strategy( const strategy_t &source,
                                               std::vector<double> &dest );

    // --------------------------------------------------------------------- //
    /*!  Extract parameter range vector from 'par_range' corresponding to
         name 'par_name' and expand strategy 'source' with
         'par_name' replaced by optimization range.
         Output vector replaces 'base_strats'
    */
    void expand_strategies_with_opt_range(
                                    const std::string &par_name,
                                    const param_ranges_t &par_range,
                                    std::vector<parameters_t> &base_strats);

    // --------------------------------------------------------------------- //
    /*! Extract attribute (metric or parameter) named 'attr_name'
        from single strategy 'source'
    */
    double strategy_attribute_by_name( const std::string &attr_name,
                                       const strategy_t &source );

    // --------------------------------------------------------------------- //
    /*! Extract maximum value of the metric named 'metric_name'
        over vector of strategies 'source'
    */
    double max_strategy_metric_by_name( const std::string &metric_name,
                                        const std::vector<strategy_t> &source );

    // --------------------------------------------------------------------- //
    /*! Set parameter value in 'parameters' corresponding to name 'par_name'
        to value 'new_value'
    */
    void set_parameter_value_by_name( const std::string &par_name,
                                      parameters_t& parameters, int new_value );

    // --------------------------------------------------------------------- //
    /*! Set parameter value in 'strategies' corresponding to name 'par_name'
        to value 'new_value'
    */
    //void set_strategy_parameter_value_by_name( const std::string &par_name,
    //                                  strategy_t& strategies, int new_value );

    // --------------------------------------------------------------------- //
    /*! Extract value of parameter  named 'par_name' from parameters_t  'source'
    */
    int parameter_by_name( const std::string &par_name,
                            const parameters_t &source );

    // --------------------------------------------------------------------- //
    /*! Get first parameter value from 'source' corresponding to
        name 'par_name'
    */
    int parameter_value_by_name( const std::string &par_name,
                                 const param_ranges_t &source );

    // --------------------------------------------------------------------- //
    /*!  From full range for all parameters 'source',

            source =  [ ("p1", [10]), ("p2", [2,4,6,8]), ... ]

         return param_ranges_t with just the first element of std::vector<int>:

            [ ("p1", [10]), ("p2", [2]), ... ]
    */
    //param_ranges_t first_param_from_range( const param_ranges_t &source );

    // --------------------------------------------------------------------- //
    /*!  From full range for all parameters 'source',

            source =  [ ("p1", [10]), ("p2", [2,4,6,8]), ... ]

         fill 'dest' with just the first element of std::vector<int>:

            [ [ ("p1", 10), ("p2", 2), ... ] ]
    */
    std::vector<parameters_t> first_parameters_from_range(
                                            const param_ranges_t &par_range );

    // --------------------------------------------------------------------- //
    /*!  Extract  parameter range  vector from 'source' corresponding to
         name 'par_name'
    */
    std::vector<int> opt_range_by_name( const std::string &par_name,
                                        const param_ranges_t &source );

    // --------------------------------------------------------------------- //
    /*!  Extract parameter range vector from 'source' corresponding to
         name 'par_name' and replace parameter vector in 'dest'
    */
    void replace_opt_range_by_name( const std::string &par_name,
                                    const param_ranges_t &source,
                                    param_ranges_t &dest );

    // --------------------------------------------------------------------- //
    /*!  Extract the parameter values from all strategies in 'source'
         (ignoring the entries with performance metrics)
         and return parameter ranges.
    */
    param_ranges_t param_ranges_from_all_strategies(
                                        const std::vector<strategy_t> &source );

    // --------------------------------------------------------------------- //
    /*!  Find strategy in 'source' equal to 'ref_strat' except with filter
        'filter_name' equal to 0.
    */
    strategy_t no_filter_strategy( std::string filter_name,
                                   strategy_t ref_strat,
                                   const std::vector<strategy_t> &source );

    // --------------------------------------------------------------------- //
    /*!  Find strategy in 'source' equal to 'ref_strat' except with two filters
        'filter_name_1', 'filter_name_2' equal to 0.
    */
    strategy_t no_two_filters_strategy( std::string filter_name_1,
                                        std::string filter_name_2,
                                        strategy_t ref_strat,
                                        const std::vector<strategy_t> &source );

    // --------------------------------------------------------------------- //
    /*!  Extract parameter range vector from all strategies in 'source'
         name 'par_name' and replace parameter vector in 'dest'
    */
    /*
    void extract_parameter_ranges_from_all_strategies(
                                    const std::vector<strategy_t> &source,
                                    param_ranges_t &dest );
    */
    // --------------------------------------------------------------------- //
    /*!  Extract parameter range vector from 'source' corresponding to
         name 'par_name' and make a new parameter vector in 'dest' where
         'par_name' is the only optimization parameter
         (all others are initialized with their starting value)
    */
    /*
    void extract_single_opt_range_by_name( const std::string &par_name,
                                           const param_ranges_t &source,
                                           param_ranges_t &dest );
    */
}



#endif
