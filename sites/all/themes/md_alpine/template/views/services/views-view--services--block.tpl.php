<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<?php
    $view_result = $view->result;
//kpr($view_result);die;
?>
<div class="container <?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <?php print $title; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($header): ?>
        <div class="view-header">
            <?php print $header; ?>
        </div>
    <?php endif; ?>

    <?php if ($exposed): ?>
        <div class="view-filters">
            <?php print $exposed; ?>
        </div>
    <?php endif; ?>

    <?php if ($attachment_before): ?>
        <div class="attachment attachment-before">
            <?php print $attachment_before; ?>
        </div>
    <?php endif; ?>
    <div class="row">
        <div class="col-md-10 col-md-offset-1">
            <div class="element-line">
                <div class="owl-single owl-carousel">
                    <?php foreach ($view_result as $key => $value) :?>
                        <!-- Item Slide -->
                        <div class="item service-element">
                            <div class="row">
                                <div class="col-md-7">
                                    <img class="img-responsive img-center img-rounded" src="<?php if(isset($value->field_field_sv_thumbnail[0])) : print image_style_url('services_thumbnail',$value->field_field_sv_thumbnail[0]['rendered']['#item']['uri']);endif;?>" alt=""/>
                                </div>
                                <div class="col-md-5">
                                    <h2><?php print $value->node_title;?></h2>
                                    <p class="lead">
                                        <?php if(isset($value->field_field_sv_summary[0])) :print $value->field_field_sv_summary[0]['rendered']['#markup'];endif;?>
                                    </p>
                                    <br />
                                    <div class="mybutton medium">
                                        <a href="<?php if(isset($value->field_field_sv_button_link[0])) :print $value->field_field_sv_button_link[0]['rendered']['#markup'];endif;?>"> <span data-hover="<?php print $value->field_field_sv_button_text[0]['rendered']['#markup'];?>"><?php print $value->field_field_sv_button_text[0]['rendered']['#markup'];?></span> </a>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <!-- Item Slide -->
                    <?php endforeach;?>

                </div>

            </div>
        </div>
    </div>
    <?php
    $service = $view->result;
    $dataCount = count($service);
    $outputArray = array_chunk($service, 4, true);
    ?>

    <?php if ($pager): ?>
        <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($attachment_after): ?>
        <div class="attachment attachment-after">
            <?php print $attachment_after; ?>
        </div>
    <?php endif; ?>

    <?php if ($more): ?>
        <?php print $more; ?>
    <?php endif; ?>

    <?php if ($footer): ?>
        <div class="view-footer">
            <?php print $footer; ?>
        </div>
    <?php endif; ?>

    <?php if ($feed_icon): ?>
        <div class="feed-icon">
            <?php print $feed_icon; ?>
        </div>
    <?php endif; ?>

</div><?php /* class view */ ?>
</div>
