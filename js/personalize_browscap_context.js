(function ($) {

    Drupal.personalize = Drupal.personalize || {};
    Drupal.personalize.visitor_context = Drupal.personalize.visitor_context || {};
    Drupal.personalize.visitor_context.browscap_context = {
        'getContext': function(enabled) {
            var context_values = Drupal.settings.personalize_browscap_context;
            if (typeof context_values === 'undefined') {
                return {};
            }
            return context_values;
        }
    };

})(jQuery);