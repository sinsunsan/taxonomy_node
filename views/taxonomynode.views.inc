<?php

/**
 * Implementation of hook_views_data().
 */
function taxonomynode_views_data() {
  $data = array();

   // Found the related term tid when we have the node nid in node view
  $data['taxonomynode']['table']['group'] = t('Taxonomy Node : Node > Term');

  $data['taxonomynode']['table']['join']['node'] = array(
      'left_field' => 'nid',
      'field' => 'nid',
  );

  $data['taxonomynode']['tid'] = array(
    'title' => 'Term ID',
    'help' => t('Term ID of the mapping term of each node.'),
    'relationship' => array(
      'base' => 'term_data',
      'field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Taxonomy Node Term'),
    ),
  );

  // Found the related node nid when we have a term tid in a term view
  $data['taxonomynode1']['table']['group'] = t('Taxonomy Node : Term > Node');
  
  $data['taxonomynode1']['table']['join']['node'] = array(
      'left_field' => 'nid',
      'field' => 'nid',
  );
  
  $data['taxonomynode1']['nid'] = array(
    'title' => 'Node ID',
    'help' => t('Node ID of the mapping node of each term.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Taxonomy Term Node'),
    ),
  );

  return $data;
}