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

<!-- Ajax Portfolio content -->
<div id="ajax-section">
    <div class="container clearfix">
        <div id="project-navigation" class="text-center">
            <ul>
                <li id="prevProject">
                    <a href="#"><i class="fontello icon-angle-circled-left icon-2x"></i></a>
                </li>
                <li id="closeProject">
                    <a href="#loader"><i class="fontello icon-cancel-circled icon-2x"></i></a>
                </li>
                <li id="nextProject">
                    <a href="#"><i class="fontello icon-angle-circled-right icon-2x"></i></a>
                </li>
            </ul>
        </div>

        <!-- Ajax loader -->
        <div id="loader"></div>
        <!-- Ajax loader -->

        <div id="ajax-content-outer">
            <div id="ajax-content-inner"></div>
        </div>
    </div>
</div>
<div class="clear"></div>
<!-- Ajax content -->

<div id="top-portfolio" class="portfolio-top"></div>
<div class="element-line">
    <div id="filters" class="mybutton small">
        <a href="#" data-filter="*"><span data-hover="Show all"><?php print t('Show all');?></span></a>
        <?php
            $taxo = taxonomy_vocabulary_machine_name_load('portfolio_taxonomy');
            $terms = taxonomy_get_tree($taxo->vid);
            foreach ($terms as $key => $value):
        ?>
        <a href="#" data-filter=".<?php print 'tid-'.$value->tid;?>"><span data-hover="<?php print $value->name;?>"><?php print $value->name;?></span></a>
        <?php endforeach;?>
    </div>
</div>
<!-- Portfolio filters -->
<div class="<?php print $classes; ?>">
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
<!-- Portfolio filters -->

<div id="portfolio-wrap">
    <?php if ($rows): ?>
        <?php print $rows; ?>
    <?php elseif ($empty): ?>
        <div class="view-empty">
            <?php print $empty; ?>
        </div>
    <?php endif; ?>
</div>


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

