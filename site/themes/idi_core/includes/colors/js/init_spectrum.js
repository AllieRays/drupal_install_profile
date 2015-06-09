/**
 * Created by cdonnelly on 3/27/15.
 */

(function ($) {
    $.fn.init_spectrum = function() {
    if (jQuery(".spectrum-color-picker").length > 0) {
        jQuery(".spectrum-color-picker").spectrum("destroy");
    }
    jQuery(".spectrum-color-picker").spectrum({
        showInput: true,
        allowEmpty: true,
        showAlpha: true,
        showInitial: true,
        showInput: true,
        preferredFormat: "hex",
        clickoutFiresChange: true,
        showButtons: false
    });
}
})(jQuery);
